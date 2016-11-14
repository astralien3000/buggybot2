from conans import ConanFile, CMake

class AversivePlusPlusModuleConan(ConanFile):
    name = "device-buggybot-adm2560"
    version = "0.1"
    requires = (
        "device/0.1@AversivePlusPlus/dev",
        "device-hal/0.1@AversivePlusPlus/dev",
        )
    exports = "*.hpp"

    def package(self):
        self.copy("*.hpp", src=".", dst="include/device")
