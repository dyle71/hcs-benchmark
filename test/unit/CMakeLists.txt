# ------------------------------------------------------------
# This file is the main CMakeLists of benchmark of headcode.space
#
# The 'LICENSE.txt' file in the project root holds the software license.
# Copyright (C) 2020-2021 headcode.space e.U.  
# Oliver Maurhart <info@headcode.space>, https://www.headcode.space
# ------------------------------------------------------------

include(GoogleTest)

include_directories(${CMAKE_SOURCE_DIR}/include ${TEST_BASE_DIR} ${CMAKE_BINARY_DIR})
set(UNIT_TEST_SRC
    test_benchmark.cpp
    test_version.cpp
)

add_executable(unit-tests ${UNIT_TEST_SRC})
target_link_libraries(unit-tests ${CONAN_LIBS_GTEST} ${CMAKE_REQUIRED_LIBRARIES})
gtest_add_tests(unit-tests "" AUTO)
