#include <coap/coap.hpp>

class ServoHandler {
public:
  inline ServoHandler(void) {}

  coap::ReturnCode handle(const coap::PacketReader& req, coap::PacketBuilder& res);
};

namespace coap {
template<>
class SimpleDiscoveryInputStream<ServoHandler> : ServoHandler {
public:
  size_t read(uint8_t* buffer, size_t size);
};
}
