#include <coap/coap.hpp>

class LabelHandler {
public:
  inline LabelHandler(void) {}

  coap::ReturnCode handle(const coap::PacketReader& req, coap::PacketBuilder& res);
};

namespace coap {
template<>
class SimpleDiscoveryInputStream<LabelHandler> : LabelHandler {
public:
  size_t read(uint8_t* buffer, size_t size);
};
}
