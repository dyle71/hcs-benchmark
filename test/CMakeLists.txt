# ------------------------------------------------------------
# This file is the main CMakeLists of benchmark of headcode.space
#
# The 'LICENSE.txt' file in the project root holds the software license.
# Copyright (C) 2020 headcode.space
# https://www.headcode.space, <info@headcode.space>
# ------------------------------------------------------------


# ------------------------------------------------------------
# googletest (internally handled as git submodule)
# if missing do a 
#   $ git submodule init
#   $ git submodule add https://github.com/google/googletest 3rd/googletest

check_library_exists(pthread pthread_kill "/usr/local/lib;/usr/lib;/lib" HAVE_PTHREAD_LIB)
if (HAVE_PTHREAD_LIB)
    set(CMAKE_REQUIRED_LIBRARIES "pthread;${CMAKE_REQUIRED_LIBRARIES}")
endif ()

if (NOT EXISTS "${CMAKE_SOURCE_DIR}/3rd/googletest/CMakeLists.txt")
    message(FATAL_ERROR "The git submodule for googletest has not been downloaded!")
endif ()

file(MAKE_DIRECTORY "${CMAKE_BINARY_DIR}/3rd/googletest")
execute_process(COMMAND "${CMAKE_COMMAND}" -G "${CMAKE_GENERATOR}" "${CMAKE_SOURCE_DIR}/3rd/googletest"
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/3rd/googletest"
)
execute_process(COMMAND "${CMAKE_COMMAND}" --build .
    WORKING_DIRECTORY "${CMAKE_BINARY_DIR}/3rd/googletest"
)
set(GTEST_INCLUDE_DIR
    "${CMAKE_SOURCE_DIR}/3rd/googletest/googletest/include"
    "${CMAKE_SOURCE_DIR}/3rd/googletest/googlemock/include"
)
set(GTEST_LIBRARY_PATH  "${CMAKE_BINARY_DIR}/3rd/googletest/lib")
set(GTEST_LIBRARY       "${GTEST_LIBRARY_PATH}/libgtest.a")
set(GTEST_MAIN_LIBRARY  "${GTEST_LIBRARY_PATH}/libgtest_main.a")
set(GMOCK_LIBRARY       "${GTEST_LIBRARY_PATH}/libgmock.a")
set(GMOCK_MAIN_LIBRARY  "${GTEST_LIBRARY_PATH}/libgmock_main.a")

find_package(GTest REQUIRED)


# ------------------------------------------------------------ 
# Workload

set(TEST_BASE_DIR ${CMAKE_CURRENT_SOURCE_DIR})

add_subdirectory(unit)
