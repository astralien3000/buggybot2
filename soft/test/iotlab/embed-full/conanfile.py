from conans import ConanFile, CMake, Embedded

class AversivePlusPlusProjectConan(ConanFile):
    name="embed-io"
    version="0.1"
    settings = "os", "compiler", "build_type", "arch", "target"
    requires = (
        "riot/0.1@AversivePlusPlus/dev",
        "stream-riot/0.1@AversivePlusPlus/dev",
        "cmake-toolchain/0.1@AversivePlusPlus/dev",
        "coap--/0.1@AversivePlusPlus/dev",
        "feetech/0.1@AversivePlusPlus/dev",
        )
    #default_options = "riot:modules=\"gnrc_netdev_default auto_init_gnrc_netif gnrc_ipv6_router_default gnrc_udp gnrc_rpl gnrc_icmpv6_echo gnrc_sock_udp shell_commands\""
    default_options = "riot:modules=\"gnrc_netdev_default auto_init_gnrc_netif gnrc_ipv6_router_default gnrc_udp gnrc_rpl auto_init_gnrc_rpl gnrc_pktdump gnrc_icmpv6_echo shell shell_commands ps netstats_l2 netstats_ipv6 netstats_rpl gnrc_sock_udp\""
    generators = "cmake", "txt"

    def imports(self):
        self.copy("toolchain.cmake")

    def build(self):
        cmake = CMake(self.settings)
        toolchain = '-DCMAKE_TOOLCHAIN_FILE=toolchain.cmake'
        self.run('cmake "%s" %s %s' % (self.conanfile_directory, cmake.command_line, toolchain))
        self.run('cmake --build . %s' % cmake.build_config)
