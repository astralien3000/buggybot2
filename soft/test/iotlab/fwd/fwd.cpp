#include <net/gnrc.h>
#include <net/gnrc/ipv6.h>
#include <net/gnrc/udp.h>

#include <periph/uart.h>

#include <coap/coap.hpp>
#include <stream/riot/uart_stream.hpp>
#include <stream/formatted_stream.hpp>

void send(const char *addr_str, uint16_t port, char *data, size_t size)
{
    ipv6_addr_t addr;

    /* parse destination address */
    if (ipv6_addr_from_str(&addr, addr_str) == NULL) {
        puts("Error: unable to parse destination address");
        return;
    }
    /* parse port */
    if (port == 0) {
        puts("Error: unable to parse destination port");
        return;
    }

    {
        gnrc_pktsnip_t *payload, *udp, *ip;
        unsigned payload_size;
        /* allocate payload */
        payload = gnrc_pktbuf_add(NULL, data, size, GNRC_NETTYPE_UNDEF);
        if (payload == NULL) {
            puts("Error: unable to copy data to packet buffer");
            return;
        }
        /* store size for output */
        payload_size = (unsigned)payload->size;
        /* allocate UDP header, set source port := destination port */
        udp = gnrc_udp_hdr_build(payload, port, port);
        if (udp == NULL) {
            puts("Error: unable to allocate UDP header");
            gnrc_pktbuf_release(payload);
            return;
        }
        /* allocate IPv6 header */
        ip = gnrc_ipv6_hdr_build(udp, NULL, &addr);
        if (ip == NULL) {
            puts("Error: unable to allocate IPv6 header");
            gnrc_pktbuf_release(udp);
            return;
        }
        /* send packet */
        if (!gnrc_netapi_dispatch_send(GNRC_NETTYPE_UDP, GNRC_NETREG_DEMUX_CTX_ALL, ip)) {
            puts("Error: unable to locate UDP thread");
            gnrc_pktbuf_release(ip);
            return;
        }
        /* access to `payload` was implicitly given up with the send operation above
         * => use temporary variable for output */
        printf("Success: send %u byte to [%s]:%u\n", payload_size, addr_str,
               port);
    }
}


static uint8_t map[12] = {14,3,4,5,6,7,8,9,10,11,12,13};

static uint16_t servo[12] = {
  512, 512, 512,
  512, 512, 512,
  512, 512, 512,
  512, 512, 512,
};

static void fwd_anim(void)
{
  for(size_t i = 0 ; i < 12 ; i++) {
    if(servo[i] > 1024) {
      puts("ERROR : invalid servo value");
      return;
    }
  }
  
  ////////
  uint8_t buf[128];
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
  send("fe80::5841:1201:e760:2a2e", 5683, (char*)pw._buffer, pw._size);
}

static void configure(void) {
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
  send("fe80::5841:1201:e760:2a2e", 5683, (char*)pw._buffer, pw._size);
}

static RIOT::UARTStream<> _uart(0, 115200);
static Aversive::Stream::FormattedStreamDecorator<RIOT::UARTStream<>> _cout(_uart);

extern "C" void fwd(void) {  
  configure();
  
  while(1) {
    if(_uart.readable() >= sizeof(servo)) {
      _uart.read((uint8_t*)servo, sizeof(servo));
      _cout << "test" << servo[0] << " " << servo[1] << " " << servo[2] << "\n";
      fwd_anim();
    }
  }
}
