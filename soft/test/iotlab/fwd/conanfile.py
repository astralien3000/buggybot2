from conans import ConanFile, CMake, Embedded

class AversivePlusPlusProjectConan(ConanFile):
    name="fwd"
    version="0.1"
    settings = "os", "compiler", "build_type", "arch", "target"
    requires = (
    "base/0.1@AversivePlusPlus/dev",
    "coap--/0.1@AversivePlusPlus/dev",
    )
    default_options = "riot:modules=\"gnrc_netdev_default auto_init_gnrc_netif gnrc_ipv6_router_default gnrc_udp gnrc_rpl gnrc_icmpv6_echo gnrc_sock_udp shell_commands\""
    generators = "cmake", "txt"

    def imports(self):
        self.copy("*.cmake", dst="toolchain", src="toolchain")
        self.copy("*.ld", dst="toolchain/linker", src="linker")

    def build(self):
        cmake = CMake(self.settings)
        toolchain = ""
        self.run('cmake "%s" %s %s' % (self.conanfile_directory, cmake.command_line, toolchain))
        self.run('cmake --build . %s' % cmake.build_config)
