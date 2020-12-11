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
    std::cout << GetMegaBitsPerSecond() << " Mbps" << std::endl;

    return 0;
}
```

Done.

**NOTE** I'm using the Googletest Suite for my test. Therefore I strongly recommend 
examining the source code in the test, since they are also meant for documentation 
and show how this code is intended to be used. Look for instance at this:


## Project layout

```
.
├── 3rd                         3rd party libraries needed (likely as git submodules).
├── cmake                       CMake additional files.
│   ├── deb-package.cmake       Building instructions for DEB packages.
│   └── rpm-package.cmake       Building instructions for RPM packages.
├── include                     Public header files. Add the path to this folder to your C++ search path.
│   └── headcode                
│       └── benchmark           Include this: <headcode/benchmark/benchmark.hpp>
├── test                        Tests.
│   └── unit                    Unit tests.
├── tools                       Various tools for run-time or build-time.
│   └── docker                  Docker builder image definitions: Dockerfiles for various platforms to build.
├── Changes.md                  Changes file.
├── CMakeLists.txt              The overall CMakeLists.txt.
├── Doxyfile                    Doxgen API documentation configuration.
├── LICENSE.txt                 The software license.
└── README.md                   This file.
```

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

_Note: Please check the test files for documentation. 
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


## Notable guidelines

* Coding Guidelines: https://google.github.io/styleguide/cppguide.html
* How (not) to write git commit messages: https://www.codelord.net/2015/03/16/bad-commit-messages-hall-of-shame/
* How to version your software: https://semver.org/
* How to write a clever "Changes" file: https://keepachangelog.com/en/1.0.0/
* Folder Convention: https://github.com/KriaSoft/Folder-Structure-Conventions

---

(C)opyright 2020 headcode.space
[https://headcode.space](https://www.headcode.space)

