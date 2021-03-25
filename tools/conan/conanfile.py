# ------------------------------------------------------------
# This file is part of benchmark of headcode.space
#
# The 'LICENSE.txt' file in the project root holds the software license.
# Copyright (C) 2020-2021 headcode.space e.U.
# Oliver Maurhart <info@headcode.space>, https://www.headcode.space
# ------------------------------------------------------------

import os
import os.path

from conans import ConanFile, tools


class HcsBenchmarkConan(ConanFile):
    """Conan package manager file. See https://conan.io"""
    name = "hcs-benchmark"
    version = "@VERSION@"
    license = "MIT"
    author = "Oliver Maurhart (oliver.maurhart@headcode.space)"
    url = "https://gitlab.com/headcode.space/benchmark"
    homepage = "https://gitlab.com/headcode.space/benchmark"
    description = "This a very tiny itzi-bitzi header-only C++17 project to enhance working benchmark."
    topics = ("benchmark", "C++17")
    no_copy_source = True
    # No settings/options are necessary, this is header only

    def source(self):
        local_source = "@CMAKE_SOURCE_DIR@"
        self.run("git clone " + (local_source or "https://gitlab.com/headcode.space/benchmark.git"))

    def package(self):
        with open('foo', 'w') as f:
            f.write('bar')
        self.copy("*.hpp", src="benchmark/include", dst="include")

    def package_id(self):
        self.info.header_only()
