#include <coap/coap.hpp>

class ConfigHandler {
public:
  inline ConfigHandler(void) {}

  coap::ReturnCode handle(const coap::PacketReader& req, coap::PacketBuilder& res);
};

namespace coap {
template<>
class SimpleDiscoveryInputStream<ConfigHandler> : ConfigHandler {
public:
  size_t read(uint8_t* buffer, size_t size);
};
}
