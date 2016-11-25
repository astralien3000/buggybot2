#include <unistd.h>
#include <cereal/archives/json.hpp>
#include <zmq.hpp>

#include <coap/coap.hpp>
#include <sys/socket.h>
#include <netinet/in.h>
#include <string.h>

#include <fcntl.h>
#include <arpa/inet.h>
#include <sys/time.h>

#include <iostream>
#include <sstream>

using namespace std;

class CmdHandler : coap::Handler {
private:
  int state = 0;
  int last_state = 0;
  
  zmq::context_t ctx {1};
  zmq::socket_t sock_teleopt_out {ctx, ZMQ_PUB};
  
  char cstab[5] = {
    's',
    'f',
    'l',
    'r',
    'a',
  };
  
private:
  void config_sock(zmq::socket_t& sock) {
    int hwm = 1;
    int linger = 0;
    sock.setsockopt(ZMQ_SNDHWM, &hwm, sizeof(hwm));
    sock.setsockopt(ZMQ_RCVHWM, &hwm, sizeof(hwm));
    sock.setsockopt(ZMQ_LINGER, &linger, sizeof(linger));
  }
  
  bool update_state(char c) {
    bool ret = false;
    
    for(int i = 0 ; i < 5 ; i++) {
      if(cstab[i] == c) {
        state = i;
      }
    }
    
    if(last_state != state) {
      stringstream oss;
      
      {
        cereal::JSONOutputArchive ar(oss);
        ar(CEREAL_NVP(state));
      }
      
      zmq::message_t msg(oss.str().size());
      oss.str().copy((char*)msg.data(), msg.size());
      
      sock_teleopt_out.send(msg, ZMQ_NOBLOCK);
      ret = true;
    }
    
    last_state = state;
    return ret;
  }
  
  char get_state(void) {
    return cstab[state];
  }
  
public:
  CmdHandler(void) {
    //sock_teleopt_out.connect("ipc://teleopt.out");
    sock_teleopt_out.connect("tcp://localhost:3333");
    
    config_sock(sock_teleopt_out);
  }
  
public:
  inline coap::Error handle(const coap::PacketReader& req, coap::PacketBuilder& res) {
    for(auto it = req.getOptionsBegin() ; it != req.getOptionsEnd() ; it++) {
      auto opt = *it;
      if(opt.getNum() == coap::OptionNum::URI_PATH &&
         strncmp("robot", (const char*)opt.getValue(), opt.getLength()) == 0) {
        
        //// GET
        if((coap::Method)req.getCode() == coap::Method::GET) {
          uint8_t c = get_state();
          
          return res.makeResponse(
                req,
                coap::ResponseCode::CONTENT,
                coap::ContentType::TEXT_PLAIN,
                &c,
                1
                );
        }
        
        //// PUT
        if((coap::Method)req.getCode() == coap::Method::PUT) {
          if(req.getPayloadLength() == 1 && update_state(req.getPayload()[0])) {
            uint8_t c = get_state();
            
            return res.makeResponse(
                  req,
                  coap::ResponseCode::CHANGED,
                  coap::ContentType::TEXT_PLAIN,
                  &c,
                  1
                  );
          }
        }
      }
    }
    
    return coap::Error::UNSUPPORTED;
  }
};

namespace coap {
template<>
class SimpleDiscoveryInputStream<CmdHandler> : CmdHandler {
public:
  size_t read(uint8_t* buffer, size_t size) {
    uint8_t* cur = buffer;
    stringstream ss;
    ss << "</robot>;ct=0,";
    
    if(ss.str().length() < size - (size_t)(cur-buffer)) {
      memcpy(cur, ss.str().c_str(), ss.str().length());
      cur += ss.str().length();
    }
    else {
      return (size_t)(cur - buffer);
    }
    
    return (size_t)(cur - buffer);
  }
};
}

void dump(const coap::PacketReader& pack) {
  cout << "version : " << (int)pack.getVersion() << endl;
  cout << "type : " << (int)pack.getType() << endl;
  cout << "code : " << (int)pack.getCode() << endl;
  cout << "id : " << (int)pack.getID() << endl;
  
  cout << "token : ";
  if(pack.getTokenLength()) {
    cout.write((const char*)pack.getToken(), pack.getTokenLength());
  }
  else {
    cout << "(empty)";
  }
  cout << endl;
  
  cout << "options {" << endl;
  for(auto it = pack.getOptionsBegin() ; it != pack.getOptionsEnd() ; it++) {
    auto& opt = *it;
    cout << "\t" << (int)opt.getNum() << " => ";
    if(opt.getLength()) {
      if(opt.getNum() == coap::OptionNum::CONTENT_FORMAT) {
        for(size_t i = 0 ; i < opt.getLength() ; i++) {
          cout << (int)opt.getValue()[i] << " ";
        }
      }
      else {
        cout.write((const char*)opt.getValue(), opt.getLength());
      }
    }
    else {
      cout << "(empty)";
    }
    cout << endl;
  }
  cout << "}" << endl;
  
  cout << "payload : ";
  if(pack.getPayloadLength()) {
    cout.write((const char*)pack.getPayload(), pack.getPayloadLength());
  }
  else {
    cout << "(empty)";
  }
  cout << endl;
}

#define PORT 5683

#ifndef RDV_ADDR
//#define RDV_ADDR "2001:660:3207:102::4"
#define RDV_ADDR "::1"
#endif
//#define RDV_PORT 5683
#define RDV_PORT 3334

void send_alive(void)
{
  struct in6_addr rdv_addr;
  if(inet_pton(AF_INET6, RDV_ADDR, &rdv_addr) != 1) {
    cout << "Error : address not valid : " << RDV_ADDR << endl;
    return;
  }
  
  struct sockaddr_in6 addr;
  bzero(&addr,sizeof(addr));
  addr.sin6_family = AF_INET6;
  addr.sin6_addr = rdv_addr;
  addr.sin6_port = htons(RDV_PORT);
  
  ////////
  uint8_t buf[128];
  coap::PacketWriter pw(buf, sizeof(buf));
  coap::EmptyPacket pack(pw);
  static uint16_t id = 0;
  
  pack.buildHeader(coap::MessageType::NONCON, (coap::ResponseCode)coap::Method::POST, id, (uint8_t*)"", 0)
      .addOption(coap::OptionNum::URI_PATH, (const uint8_t*)"alive", strlen("alive"))
      .addPayload((const uint8_t*)"Alive", strlen("Alive"))
      ;
  
  if(pack.getError() != coap::Error::NONE) {
    cout << "Error while building packet" << endl;
    return;
  }
  
  id++;
  ////////
  
  int sock = socket(AF_INET6, SOCK_DGRAM, 0);
    
  if(sendto(sock, pw._buffer, pw._size, 0, (struct sockaddr*)&addr, sizeof(addr)) < 0) {
    cout << "Error : Cannot send Alive message " << endl;
  }
  else {
    cout << "--- Alive ---" << endl;
    coap::PacketReader pack(pw._buffer, pw._size);
    dump(pack);
  }
  
  close(sock);
}

int main(int, char**) {
  // CoAP config
  CmdHandler dummy;
  coap::SimpleDiscoveryHandler<decltype(dummy)> discov(dummy);
  coap::ChainHandler<decltype(discov), decltype(dummy)> handler(discov, dummy);
  coap::Parser<decltype(handler)> parser(handler);
  uint8_t buf_raw[1024];
  coap::Buffer buf {buf_raw,sizeof(buf_raw)};
  
  int fd;
  
  struct sockaddr_in6 servaddr, cliaddr;
  fd = socket(AF_INET6,SOCK_DGRAM,0);
  bzero(&servaddr,sizeof(servaddr));
  servaddr.sin6_family = AF_INET6;
  servaddr.sin6_addr = in6addr_any;
  servaddr.sin6_port = htons(PORT);
  
  fcntl(fd, F_SETFL, fcntl(fd, F_GETFL)|O_NONBLOCK);
  bind(fd,(struct sockaddr *)&servaddr, sizeof(servaddr));
  
  struct timeval t1, t2;
  send_alive();
  gettimeofday(&t1, 0);
  
  while(1) {
    size_t n;
    socklen_t len = sizeof(cliaddr);
    
    //cout << recvfrom(fd, 0, 0, MSG_PEEK|MSG_TRUNC, 0,0) << endl;
    if(0 < recvfrom(fd, 0, 0, MSG_PEEK|MSG_TRUNC, 0,0)) {
      n = recvfrom(fd, buf.data, buf.len, 0, (struct sockaddr *)&cliaddr, &len);
      
      {
        cout << endl << "--- REQUEST ---" << endl;
        coap::PacketReader pack(buf.data, n);
        dump(pack);
      }
      
      coap::ReadOnlyBuffer res = parser.parse(coap::ParserInput{{buf.data, n}, {buf.data, buf.len}});
      
      if(res.data != NULL) {
        cout << endl << "--- RESPONSE ---" << endl;
        coap::PacketReader pack(res.data, res.len);
        dump(pack);
      }
      
      sendto(fd, res.data, res.len, 0, (struct sockaddr *)&cliaddr, sizeof(cliaddr));
    }

    usleep(1000000/20);
    
    gettimeofday(&t2, 0);
    //cout << t2.tv_sec - t1.tv_sec << endl;
    if(20 < t2.tv_sec - t1.tv_sec) {
      send_alive();
      gettimeofday(&t1, 0);
    }
  }
  
  return 0;
}
