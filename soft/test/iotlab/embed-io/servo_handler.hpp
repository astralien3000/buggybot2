#include <coap/coap.hpp>

class DummyHandler {
public:
  inline DummyHandler(void) {}

  coap::Error handle(const coap::PacketReader& req, coap::PacketBuilder& res);
};

namespace coap {
template<>
class SimpleDiscoveryInputStream<DummyHandler> : DummyHandler {
public:
  size_t read(uint8_t* buffer, size_t size);
};
}
