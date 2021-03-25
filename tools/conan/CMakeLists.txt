# ------------------------------------------------------------
# This file is the main CMakeLists of benchmark of headcode.space
#
# The 'LICENSE.txt' file in the project root holds the software license.
# Copyright (C) 2020-2021 headcode.space e.U.  
# Oliver Maurhart <info@headcode.space>, https://www.headcode.space
# ------------------------------------------------------------


configure_file(conanfile.py conanfile.py @ONLY)
add_custom_target(conan
    COMMAND conan create . ${CONAN_USER}/${CONAN_CHANNEL}
    COMMENT "Creating and installing conan package locally...")
