from conans import ConanFile, CMake

class AversivePlusPlusProjectConan(ConanFile):
    name="ik"
    version="0.1"
    settings = "os", "compiler", "build_type", "arch", "target"
    requires = (
        "base/0.1@AversivePlusPlus/dev",
        )
    generators = "cmake"

    def build(self):
        cmake = CMake(self.settings)

        self.run('cmake "%s" %s' % (self.conanfile_directory, cmake.command_line))
        self.run('cmake --build . %s' % cmake.build_config)
