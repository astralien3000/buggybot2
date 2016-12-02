#include <net/af.h>
#include <net/sock/udp.h>

#define ENABLE_DEBUG (1)
#include <debug.h>

#include <coap/coap.hpp>
#include "servo_handler.hpp"

#define COAP_SERVER_PORT    (5683)

DummyHandler dummy;
coap::SimpleDiscoveryHandler<decltype(dummy)> discov(dummy);
coap::ChainHandler<decltype(discov), decltype(dummy)> handler(discov, dummy);
coap::Parser<decltype(handler)> parser(handler);
uint8_t buf_raw[1024];

static void _clean_buf(void) {
  for(size_t i = 0 ; i < sizeof(buf_raw) ; i++) {
    buf_raw[i] = 0;
  }
}

void microcoap_server_loop(void) {
  sock_udp_ep_t local = {};
  local.family = AF_INET6;
  local.port = COAP_SERVER_PORT;
  sock_udp_ep_t remote;
  
  sock_udp_t sock;
  
  int rc = sock_udp_create(&sock, &local, NULL, 0);
  
  while (1) {
    _clean_buf();
    coap::Buffer buf {buf_raw,sizeof(buf_raw)};
    
    DEBUG("Waiting for incoming UDP packet...\n");
    rc = sock_udp_recv(&sock, (char *)buf.data, buf.len,
                       SOCK_NO_TIMEOUT, &remote);
    if (rc < 0) {
      DEBUG("Error in conn_udp_recvfrom(). rc=%u\n", rc);
      continue;
    }
    
    size_t n = rc;

    {
      DEBUG("--- REQUEST ---\n");
      //cout << endl << "--- REQUEST ---" << endl;
      //coap::PacketReader pack(buf.data, n);
      //dump(pack);
    }

    coap::ReadOnlyBuffer res = parser.parse(coap::ParserInput{{buf.data, n}, {buf.data, buf.len}});

    if(res.data != NULL) {
      DEBUG("--- RESPONSE ---\n");
      //cout << endl << "--- RESPONSE ---" << endl;
      //coap::PacketReader pack(res.data, res.len);
      //dump(pack);
    }

    /* send reply via UDP */
    rc = sock_udp_send(&sock, res.data, res.len, &remote);
    if (rc < 0) {
      DEBUG("Error sending CoAP reply via udp; %u\n", rc);
    }
  }
}
