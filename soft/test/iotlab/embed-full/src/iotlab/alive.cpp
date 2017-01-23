#include <net/sock/udp.h>
#include <net/ipv6/addr.h>

#include <thread.h>
#include <xtimer.h>

#include <string.h>

#include <coap/coap.hpp>

#ifndef RDV_ADDR
#define RDV_ADDR "2001:660:3207:102::4"
//#define RDV_ADDR "fd00:dead:beef::1"
#endif
#define RDV_PORT 5683

#define PERIOD_S (20)
#define PERIOD_US (PERIOD_S*1000000)

static void send_alive(void)
{
  puts("~~ ALIVE ~~");

  sock_udp_ep_t local = {};
  local.family = AF_INET6;
  local.netif = SOCK_ADDR_ANY_NETIF;

  sock_udp_ep_t remote = {};
  remote.family = AF_INET6;
  remote.port = RDV_PORT;

  if(ipv6_addr_from_str((ipv6_addr_t*)remote.addr.ipv6, RDV_ADDR) == NULL) {
    puts("Error ipv6_addr_from_str " RDV_ADDR);
    return;
  }

  ////////
  uint8_t buf[128];
  coap::PacketWriter pw(buf, sizeof(buf));
  coap::EmptyPacket pack(pw);
  static uint16_t id = 0;

  pack.buildHeader(coap::MessageType::NONCON, (coap::ResponseCode)coap::MethodCode::POST, id, (uint8_t*)"", 0)
      .addOption(coap::OptionNum::URI_PATH, (const uint8_t*)"alive", strlen("alive"))
      .addPayload((const uint8_t*)"Alive", strlen("Alive"))
      ;

  if(pack.getError() != coap::Error::NONE) {
    puts("Error while building packet");
    return;
  }

  id++;
  ////////

  sock_udp_t sock;

  if(sock_udp_create(&sock, &local, &remote, 0) < 0) {
    puts("Error sock_udp_create");
    return;
  }

  if(sock_udp_send(&sock, pw._buffer, pw._size, &remote) < 0) {
    puts("Error sock_udp_send");
    sock_udp_close(&sock);
    return;
  }

  sock_udp_close(&sock);
}

void alive_loop(void) {
  uint64_t t1 = 0;
  uint64_t t2 = 0;

  t1 = xtimer_now_usec64();
  xtimer_usleep64(PERIOD_US);

  while(1) {
    t2 = xtimer_now_usec64();

    if(PERIOD_US < t2-t1) {
      t1 = t2;
      send_alive();
      xtimer_usleep64(PERIOD_US);
    }
    else {
      xtimer_usleep64(PERIOD_US/4);
    }
  }
}
