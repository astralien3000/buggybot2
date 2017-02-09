#include <coap/coap.hpp>

class AnimHandler {
public:
  inline AnimHandler(void) {}

  coap::ReturnCode handle(const coap::PacketReader& req, coap::PacketBuilder& res);
};

namespace coap {
template<>
class SimpleDiscoveryInputStream<AnimHandler> : AnimHandler {
public:
  size_t read(char* buffer, size_t size);
};
}
