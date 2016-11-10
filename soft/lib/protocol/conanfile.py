from conans import ConanFile, CMake

class AversivePlusPlusModuleConan(ConanFile):
    name = "buggybot-protocol"
    version = "0.1"
    require = (
        "base/0.1@AversivePlusPlus/dev",
        "container/0.1@AversivePlusPlus/dev",
        )
    exports = "*.hpp"

    def package(self):
        self.copy("*.hpp", src=".", dst="include/protocol")
