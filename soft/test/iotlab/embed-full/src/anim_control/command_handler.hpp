#include <coap/coap.hpp>

class CommandHandler {
public:
  inline CommandHandler(void) {}

  coap::ReturnCode handle(const coap::PacketReader& req, coap::PacketBuilder& res);
};

namespace coap {
template<>
class SimpleDiscoveryInputStream<CommandHandler> : CommandHandler {
public:
  size_t read(char* buffer, size_t size);
};
}
