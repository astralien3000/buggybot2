/*
 * Copyright (C) 2015 Kaspar Schleiser <kaspar@schleiser.de>
 *
 * This file is subject to the terms and conditions of the GNU Lesser
 * General Public License v2.1. See the file LICENSE in the top level
 * directory for more details.
 */

#include <net/af.h>
#include <net/sock/udp.h>

#define ENABLE_DEBUG (1)
#include <debug.h>

#include <coap/coap.hpp>

#define COAP_SERVER_PORT    (5683)

class DummyHandler {
protected:
  const char* _prefix;

public:
  DummyHandler(const char* prefix)
    : _prefix(prefix) {
  }

  inline coap::Error handle(const coap::PacketReader& req, coap::PacketBuilder& res) {
    for(auto it = req.getOptionsBegin() ; it != req.getOptionsEnd() ; it++) {
      auto opt = *it;
      if(opt.getNum() == coap::OptionNum::URI_PATH &&
         strncmp(_prefix, (const char*)opt.getValue(), opt.getLength()) == 0) {
        return res.makeResponse(
              req,
              coap::ResponseCode::CONTENT,
              coap::ContentType::TEXT_PLAIN,
              (const uint8_t*)_prefix,
              strlen(_prefix)
              );
      }
    }

    return coap::Error::UNSUPPORTED;
  }
};

namespace coap {
template<>
class SimpleDiscoveryInputStream<DummyHandler> : DummyHandler {
public:
  size_t read(uint8_t* buffer, size_t size) {
    const char* dirs[] = { "test", "miew", "lool" };
    char* cur = (char*)buffer;
    
    (void) dirs;
    for(size_t i = 0 ; i < 3 ; i++) {
      strcpy(cur, "</");
      cur += strlen("</");

      strcpy(cur, this->_prefix);
      cur += strlen(this->_prefix);

      strcpy(cur, "/");
      cur += strlen("/");
      
      strcpy(cur, dirs[i]);
      cur += strlen(dirs[i]);

      strcpy(cur, ">;ct=0,");
      cur += strlen(">;ct=0,");
    }
    
    return (size_t)((uint8_t*)cur - buffer);
  }
};
}

DummyHandler dummy("dummy1");
coap::SimpleDiscoveryHandler<decltype(dummy)> discov(dummy);
coap::ChainHandler<decltype(discov), decltype(dummy)> handler(discov, dummy);
coap::Parser<decltype(handler)> parser(handler);
uint8_t buf_raw[1024];
coap::Buffer buf {buf_raw,sizeof(buf_raw)};

extern "C" void microcoap_server_loop(void) {
  sock_udp_ep_t local = {};
  local.family = AF_INET6;
  local.port = COAP_SERVER_PORT;
  sock_udp_ep_t remote;
  
  sock_udp_t sock;
  
  int rc = sock_udp_create(&sock, &local, NULL, 0);
  
  while (1) {
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
