import os

from conans import ConanFile, tools


class HcsBenchmarkConan(ConanFile):
    name = "hcs-benchmark"
    version = "1.0.2"
    license = "MIT"
    author = "Oliver Maurhart (oliver.maurhart@headcode.space)"
    url = "https://gitlab.com/headcode.space/benchmark"
    description = "This a very tiny itzi-bitzi header-only C++17 project to enhance working benchmark."
    topics = ("benchmark", "C++17")
    no_copy_source = True
    # No settings/options are necessary, this is header only

    def source(self):
        self.run("git clone https://gitlab.com/headcode.space/benchmark.git")

    def package(self):
        self.copy("*.hpp", src="benchmark/include", dst="include")

    def package_id(self):
        self.info.header_only()
