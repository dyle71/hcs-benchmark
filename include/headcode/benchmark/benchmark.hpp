/*
 * @file    benchmark.hpp
 *
 * This file is part of the headcode.space benchmark.
 *
 * The 'LICENSE.txt' file in the project root holds the software license.
 * Copyright (C) 2020-2021 headcode.space e.U.
 * Oliver Maurhart <info@headcode.space>, https://www.headcode.space
 */

#ifndef HEADCODE_SPACE_BENCHMARK_BENCHMARK_HPP
#define HEADCODE_SPACE_BENCHMARK_BENCHMARK_HPP

#include <chrono>
#include <iomanip>
#include <sstream>
#include <string>


/**
 * @brief   The headcode benchmark namespace
 */
namespace headcode::benchmark {


/**
 * @brief Throughput data.
 */
struct Throughput {
    std::chrono::microseconds elapsed_{0};        //!< @brief Number of microseconds elapsed.
    std::uint64_t bytes_ = 0;                     //!< @brief Number of bytes processed.
};

/**
 * @brief   Returns the elapsed milliseconds since a point in time.
 * @param   since       the reference point in time
 * @return  microseconds passed since the reference point
 */
inline std::chrono::microseconds GetElapsedMicroSeconds(std::chrono::high_resolution_clock::time_point since) {
    return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - since);
}

/**
 * @brief   Returns the bits per second
 * @param   throughput          the throughput data
 * @return  bps
 */
inline double GetBitsPerSecond(Throughput throughput) {
    double elapsed_us = throughput.elapsed_.count();
    if (elapsed_us != 0) {
        return static_cast<double>(throughput.bytes_ << 3) / (elapsed_us / 1'000'000.0);
    }
    return 0;
}

/**
 * @brief   Returns the kilo-bits per second
 * @param   throughput          the throughput data
 * @return  kbps
 */
inline double GetKiloBitsPerSecond(Throughput throughput) {
    return GetBitsPerSecond(throughput) / 1'000.0;
}

/**
 * @brief   Returns the Mega-bits per second
 * @param   throughput          the throughput data
 * @return  Mbps
 */
inline double GetMegaBitsPerSecond(Throughput throughput) {
    return GetBitsPerSecond(throughput) / 1'000'000.0;
}

/**
 * @brief   Returns the Giga-bits per second
 * @param   throughput          the throughput data
 * @return  Gbps
 */
inline double GetGigaBitsPerSecond(Throughput throughput) {
    return GetBitsPerSecond(throughput) / 1'000'000'000.0;
}

/**
 * @brief   Create a string output of the throughput numbers.
 * @param   throughput      the throughput data
 * @param   indent          the indent in each line
 * @return  A multi-line string holding the numbers.
 */
inline std::string StreamPerformanceIndicators(Throughput throughput, std::string const & indent = {}) {
    std::stringstream ss;
    ss << indent << throughput.elapsed_.count() << " us\n";
    ss << indent << std::fixed << std::setprecision(3) << GetBitsPerSecond(throughput) << " bps\n";
    ss << indent << std::fixed << std::setprecision(3) << GetKiloBitsPerSecond(throughput) << " kbps\n";
    ss << indent << std::fixed << std::setprecision(3) << GetMegaBitsPerSecond(throughput) << " Mbps\n";
    ss << indent << std::fixed << std::setprecision(3) << GetGigaBitsPerSecond(throughput) << " Gbps\n";
    return ss.str();
}


}


#endif
