# benchmark

This a very tiny itzi-bitzi header-only C++17 project to enhance working benchmark:

* start some processing
* make a stop
* count bps

This little tool should be non-intrusive to existing code and relies on the `high_precision_clock` of modern C++.

It centers around the idea of a `Throughput` struct holding an amount (actually "bytes processed") combined
with a duration (in microseconds) plus accompanying convenience functions.


## Usage example

```c++
#include <chrono>
#include <iostream>
#include <headcode/benchmark/benchmark.hpp>

using headcode::benchmark;

int main(int argc, char ** argv) {

    auto time_start = std::chrono::high_resolution_clock::now();

    // do some heave time consuming work
    unsigned int bytes_produced = heavy_computing();
    Throughput throughput{GetElapsedMicroSeconds(time_start), bytes_produced};
    
    // tell the user
    std::cout << GetMegaBitsPerSecond(throughput) << " Mbps" << std::endl;

    return 0;
}
```

Done.


## Philosophy

All `headcode.space` software follows these directives:

1. Provide very **high quality** C++ software. That's the topmost goal.

2. Provide appealing C++ software, i.e. software which is **easily read and understood**.
   Second goal.

3. Provide software with **super minimal public interfaces**. I try to really provide the absolute
   minimum without any bloat. The users of the software should only include the main header file
   (e.g. `#include <headcode/logger/logger.hpp>`) and nothing else. These are self-contained and
   rely only on C++ standard headers. No additional 3rd party headers required. Third goal.

4. Provide libraries and binaries with **little to no runtime dependencies**. Yet, linkage might
   require additional libraries (sometimes from `headcode.space` sometimes else). Whenever
   possible I strive to go for the *static libraries*, because a) the resulting binaries when
   linked against these libraries have little to no runtime dependency and can be installed
   directly with a mere `copy` and b) they are smaller too, since the linkers tend to strip off
   stuff which is not needed.

I'm by no means perfect. There's always room for improvements and there are sure still bugs.
If you have any suggestions please drop in an email at https://gitlab.com/headcode.space/benchmark/-/issues.


## API

Since this thing here is so small, there isn't really much to say, is it?

The prime structure is
```c++
struct Throughput {
   std::chrono::microseconds elapsed_{0};
   std::uint64_t bytes_ = 0;
};
```
which holds a couple of bytes for a duration of microseconds.

Then `GetElapsedMicroSeconds(std::chrono::high_resolution_clock::time_point since)` returns the number
of microseconds between `since` and the function call.

With this in mind, one can get
* `GetBitsPerSecond(Throughput tp)`: bps
* `GetKiloBitsPerSecond(Throughput tp)`:  kbps
* `GetMegaBitsPerSecond(Throughput tp)`: Mbps
* `GetGigaBitsPerSecond(Throughput tp)`: Gbps

(All these based on the ISO SI basis of **1000**. Not IEC kibi, mebi, and gibi with a base of 1024).


After an installation you'll find a doxygen documentation in your usual `doc` folder, which provides more
details.


## Project layout

```
.
├── 3rd                         3rd party libraries needed (likely as git submodules).
├── cmake                       CMake additional files.
├── include                     Public header files. Add the path to this folder to your C++ search path.
│   └── headcode                
│       └── benchmark           Here is the main include: <headcode/benchmark/benchmark.hpp>
├── test                        Tests.
│   └── unit                    Unit tests.
├── tools                       Various tools for run-time or build-time.
│   ├── docker                  Docker builder image definitions: Dockerfiles for various platforms to build.
│   └── package                 Package related files.
├── Changes.md                  Changes file.
├── CMakeLists.txt              The overall CMakeLists.txt.
├── Doxyfile                    Doxgen API documentation configuration.
├── LICENSE.txt                 The software license.
└── README.md                   This file.
```

## Installation

I provide binary installation packages for some operating systems
[here](https://gitlab.com/headcode.space/benchmark/-/packages).


## Build

### Dependencies

- cmake
- gcc (with g++) or clang (witch clang++)
- git
- make
- doxygen (with graphviz)
- [googletest](https://github.com/google/googletest) (as submodule)

When cloning this project execute the following to clone submodules as well:

```bash
$ git submodule init
$ git submodule update
```

or simply clone with the `--recurse-submodule` option:
```bash
$ git clone --recurse-submodules
```

#### Native build

benchmark is a [cmake](https://cmake.org) project with out-of-source builds in
a dedicated folder, usually labeled "build".

```bash
$ mkdir build && cd build
$ cmake ..
$ make
```

## Test

After compilation run ctest
```bash
$ cd build
$ ctest
```
Or
```bash
$ cd build
$ make test
```

_Note: Please check the [test files](test/unit/) for documentation. 
The tests are easy to read and tell you how the code is intended to be used._ 

### Test Coverage

You may also run in-deep test coverage profiling. For this, you have to turn on profiling mode:
```bash
$ cd build
$ cmake -D PROFILING_MODE_ENABLED=on ..
```

Then compile as usual and run the tests. After the tests make the `run-gcovr` target: 
```bash
$ make test
$ make run-gcovr
```

This will give you the test coverage on stdout as well as:
* `gcovr-coverage.info`:  this is the coverage info file created by gcovr
* `gcovr-report.xml`: this is the gcovr report file in xml
* `coverge-html`: this is the folder in which detailed html info of collected coverage resides
  (open up the file `coverage-html/index.html` in a browser of your choice)

in the build folder.


## Installable package creation

This project supports the creation of `DEB` and `RPM` files. This is done by specifying
the `CPACK_GENERATOR` while configuring the project. 

To create an installable `DEB`:
```bash
$ cd build
$ cmake -D CMAKE_BUILD_TYPE=Release -D CPACK_GENERATOR=DEB ..
...
$ make
...
$ make package
```

To create an installable `RPM`:
```bash
$ cd build
$ cmake -D CMAKE_BUILD_TYPE=Release -D CPACK_GENERATOR=RPM ..
...
$ make
...
$ make package
```


## Notable guidelines

* Coding Guidelines: https://google.github.io/styleguide/cppguide.html
* How (not) to write git commit messages: https://www.codelord.net/2015/03/16/bad-commit-messages-hall-of-shame/
* How to version your software: https://semver.org/
* How to write a clever "Changes" file: https://keepachangelog.com/en/1.0.0/
* Folder Convention: https://github.com/KriaSoft/Folder-Structure-Conventions

---

Copyright (C) 2020-2021 headcode.space e.U.  
Oliver Maurhart <info@headcode.space>  
[https://headcode.space](https://www.headcode.space)  
