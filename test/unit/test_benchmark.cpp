/*
 * This file is part of the headcode.space mem.
 *
 * The 'LICENSE.txt' file in the project root holds the software license.
 * Copyright (C) 2020-2021 headcode.space e.U.  
 * Oliver Maurhart <info@headcode.space>, https://www.headcode.space
 */

#include <gtest/gtest.h>

#include <headcode/benchmark/benchmark.hpp>

using namespace headcode::benchmark;


TEST(Benchmark, empty) {
    ASSERT_TRUE(true);
}


TEST(Benchmark, zero) {
    auto ms = headcode::benchmark::GetElapsedMicroSeconds(std::chrono::high_resolution_clock::now());
    EXPECT_GE(ms.count(), 0);
    EXPECT_LE(ms.count(), 10);
}


TEST(Benchmark, zero_bps) {
    headcode::benchmark::Throughput throughput;
    auto bps = headcode::benchmark::GetBitsPerSecond(throughput);
    EXPECT_EQ(bps, 0ul);
}


TEST(Benchmark, zero_kbps) {
    headcode::benchmark::Throughput throughput;
    auto bps = headcode::benchmark::GetKiloBitsPerSecond(throughput);
    EXPECT_EQ(bps, 0ul);
}


TEST(Benchmark, zero_Mbps) {
    headcode::benchmark::Throughput throughput;
    auto bps = headcode::benchmark::GetMegaBitsPerSecond(throughput);
    EXPECT_EQ(bps, 0ul);
}


TEST(Benchmark, zero_Gbps) {
    headcode::benchmark::Throughput throughput;
    auto bps = headcode::benchmark::GetGigaBitsPerSecond(throughput);
    EXPECT_EQ(bps, 0ul);
}

TEST(Benchmark, regular_bps) {
    headcode::benchmark::Throughput throughput = {std::chrono::microseconds{1'000'000}, 1'000'000'000};
    auto bps = headcode::benchmark::GetBitsPerSecond(throughput);
    EXPECT_EQ(bps, 8'000'000'000ul);
}


TEST(Benchmark, regular_kbps) {
    headcode::benchmark::Throughput throughput = {std::chrono::microseconds{1'000'000}, 1'000'000'000};
    auto bps = headcode::benchmark::GetKiloBitsPerSecond(throughput);
    EXPECT_EQ(bps, 8'000'000ul);
}


TEST(Benchmark, regular_Mbps) {
    headcode::benchmark::Throughput throughput = {std::chrono::microseconds{1'000'000}, 1'000'000'000};
    auto bps = headcode::benchmark::GetMegaBitsPerSecond(throughput);
    EXPECT_EQ(bps, 8'000ul);
}


TEST(Benchmark, regular_Gbps) {
    headcode::benchmark::Throughput throughput = {std::chrono::microseconds{1'000'000}, 1'000'000'000};
    auto bps = headcode::benchmark::GetGigaBitsPerSecond(throughput);
    EXPECT_EQ(bps, 8ul);
}