/*
 * This file is part of the headcode.space benchmark.
 *
 * The 'LICENSE.txt' file in the project root holds the software license.
 * Copyright (C) 2020-2021 headcode.space e.U.  
 * Oliver Maurhart <info@headcode.space>, https://www.headcode.space
 */

#include <gtest/gtest.h>

#include <headcode/benchmark/version.hpp>


TEST(Version, regular) {
    std::uint32_t version = MAKE_VERSION(VERSION_MAJOR, VERSION_MINOR, VERSION_PATCH);
    EXPECT_EQ(headcode::benchmark::GetCurrentVersion(), version);
    EXPECT_STREQ(headcode::benchmark::GetVersionString().c_str(), VERSION);
}


TEST(Version, V1_1_0) {
    std::uint32_t version = MAKE_VERSION(1, 1, 0);
    EXPECT_EQ(static_cast<unsigned int>((1) << 24 | (1) << 16 | (0)), version);
    EXPECT_EQ(GetHCSBenchmarkVersion_1_1_0(), version);
}


TEST(Version, V1_1_1) {
    std::uint32_t version = MAKE_VERSION(1, 1, 1);
    EXPECT_EQ(static_cast<unsigned int>((1) << 24 | (1) << 16 | (1)), version);
    EXPECT_EQ(GetHCSBenchmarkVersion_1_1_1(), version);
}


TEST(Version, V1_1_2) {
    std::uint32_t version = MAKE_VERSION(1, 1, 2);
    EXPECT_EQ(static_cast<unsigned int>((1) << 24 | (1) << 16 | (2)), version);
    EXPECT_EQ(GetHCSBenchmarkVersion_1_1_2(), version);
}
