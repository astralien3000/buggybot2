#include <net/af.h>
#include <net/sock/udp.h>

#define ENABLE_DEBUG (1)
#include <debug.h>

#include <coap/coap.hpp>
#include "servo_collection/servo_handler.hpp"
#include "servo_collection/anim_handler.hpp"
#include "servo_mapper/label_handler.hpp"

#define COAP_SERVER_PORT    (5683)

static ServoHandler servo;
static AnimHandler anim;
static LabelHandler label;
static coap::ChainHandler<AnimHandler, ServoHandler> tmp1(anim, servo);
static coap::ChainHandler<decltype(tmp1), decltype(label)> root(tmp1, label);
static coap::SimpleDiscoveryHandler<decltype(root)> discov(root);
static coap::ChainHandler<decltype(discov), decltype(root)> handler(discov, root);
static coap::Parser<decltype(handler)> parser(handler);
static uint8_t buf_raw[1024];

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
    rc = sock_udp_recv(&sock, (char *)buf.data, buf.len, SOCK_NO_TIMEOUT, &remote);
    if (rc < 0) {
      DEBUG("Error in sock_udp_recv(). rc=%u\n", rc);
      continue;
    }
    
    size_t n = rc;

    {
      DEBUG("--- REQUEST ---\n");
      //cout << endl << "--- REQUEST ---" << endl;
      //coap::PacketReader pack(buf.data, n);
      //dump(pack);
    }

    coap::ParserOutput out = parser.parse(coap::ParserInput{{buf.data, n}, {buf.data, buf.len}});

    if(out.res.data != NULL) {
      DEBUG("--- RESPONSE ---\n");
      //cout << endl << "--- RESPONSE ---" << endl;
      //coap::PacketReader pack(res.data, res.len);
      //dump(pack);
    }

    if(out.rc == coap::ReturnCode::SEND) {
      rc = sock_udp_send(&sock, out.res.data, out.res.len, &remote);
      if (rc < 0) {
        DEBUG("Error sending CoAP reply via udp; %u\n", rc);
      }
    }
  }
}
