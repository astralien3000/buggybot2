#include <stdint.h>
#include <iostream>

#include <zmq.hpp>
#include <cereal/types/vector.hpp>
#include <cereal/archives/json.hpp>
#include <cereal/archives/binary.hpp>
#include <messages/servo_action.hpp>
#include <messages/id_value.hpp>

#include <coap/coap.hpp>
#include <base/integer.hpp>
#include <string.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include <sys/socket.h>
#include <unistd.h>

using namespace Aversive::Base;
using namespace std;

////////////////////////////////////////////////////////////////
// App data

static uint8_t map[12] = {14,3,4,5,6,7,8,9,10,11,12,13};

static uint16_t servo[12] = {
  512, 512, 512,
  512, 512, 512,
  512, 512, 512,
  512, 512, 512,
};

////////////////////////////////////////////////////////////////
// ZMQ

void config_sock(zmq::socket_t& sock) {
  int hwm = 1;
  int linger = 0;
  sock.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
  sock.setsockopt(ZMQ_LINGER, &linger, sizeof(linger));
}

////////////////////////////////////////////////////////////////
// CoAP
const char* addr_str = "2001:db8::5841:1201:e760:2a2e";
const u16 port = 5683;

struct sockaddr_in6 si_other;
int sock_fd;

void die(const char* s) {
  perror(s);
  throw 0;
}

void send(char* data, size_t size) {
  if(sendto(sock_fd, data, size, 0, (struct sockaddr*)&si_other, sizeof(si_other))==-1) {
    die("sendto()");
  }
}

static void fwd_anim(void) {
  //cout << "send" << endl;
  
  ////////
  uint8_t buf[256];
  coap::PacketWriter pw(buf, sizeof(buf));
  coap::EmptyPacket pack(pw);
  static uint16_t id = 0;
  
  pack.buildHeader(coap::MessageType::NONCON, (coap::ResponseCode)coap::Method::POST, id, (uint8_t*)"", 0)
      .addOption(coap::OptionNum::URI_PATH, (const uint8_t*)"anim", strlen("anim"))
      .addPayload((const uint8_t*)servo, sizeof(servo))
      ;
  
  if(pack.getError() != coap::Error::NONE) {
    puts("Error while building packet");
    return;
  }
  
  id++;
  ////////
  send((char*)pw._buffer, pw._size);
}

static void configure(void) {
  cout << "configure" << endl;
  
  ////////
  uint8_t buf[128];
  coap::PacketWriter pw(buf, sizeof(buf));
  coap::EmptyPacket pack(pw);
  static uint16_t id = 0;
  
  pack.buildHeader(coap::MessageType::NONCON, (coap::ResponseCode)coap::Method::POST, id, (uint8_t*)"", 0)
      .addOption(coap::OptionNum::URI_PATH, (const uint8_t*)"map", strlen("map"))
      .addPayload((const uint8_t*)map, sizeof(map))
      ;
  
  if(pack.getError() != coap::Error::NONE) {
    puts("Error while building packet");
    return;
  }
  
  id++;
  ////////
  send((char*)pw._buffer, pw._size);
}



int main(int, char**) {
  // ZMQ
  zmq::context_t ctx {5};
  zmq::socket_t out{ctx, ZMQ_SUB};
  out.bind("ipc://embed.out");
  out.setsockopt(ZMQ_SUBSCRIBE, 0, 0);
  config_sock(out);
  
  // CoAP
  if((sock_fd=socket(AF_INET6, SOCK_DGRAM, IPPROTO_UDP)) == -1) {
    die("socket");
  }
  
  memset((char *) &si_other, 0, sizeof(si_other));
  si_other.sin6_family = AF_INET6;
  si_other.sin6_port = htons(port);
  
  if(inet_pton(AF_INET6, addr_str, &si_other.sin6_addr) == 0) {
    die("inet_pton()");
  }
  
  static int ccount = 0;
  configure();
  
  // Main Loop
  while(1) {
    if(++ccount >= 2000) {
      ccount = 0;
      configure();
    }
    
    zmq::message_t msg;
    out.recv(&msg);
    if(msg.size()) {
      std::stringstream ss;
      ss.write((char*)msg.data(), msg.size());
      
      vector<HardwareServoAction> hsas;
      
      {
        cereal::BinaryInputArchive ar(ss);
        ar(hsas);
      }
      
      for(int i = 0 ; i < 12 ; i++) {
        servo[i] = 512;
      }
      
      for(auto it = hsas.begin() ; it != hsas.end() ; it++) {
        HardwareServoAction& hsa = *it;
        
        if(0 <= hsa.position && hsa.position <= 1024) {
          bool found = false;
          for(int i = 0 ; i < 12 ; i++) {
            if(map[i] == hsa.id) {
              servo[i] = hsa.position;
              found = true;
            }
          }
          if(!found) {
            cout << "invalid servo id : " << hsa.id << endl;
          }
        }
        else {
          cout << "Invalid servo " << (u16)hsa.id << " COMMAND : " << hsa.position << endl;
        }
      }
      
      fwd_anim();
    }
  }
  
  return 0;
}
