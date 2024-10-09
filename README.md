# Clang Coverage Test

This repository hosts an example of how to evaluate coverage for libraries built with CMake.

## Prerequisite

In order to properly execute it's highly recommended to use a container with the accompanying [Dockerfile](./Dockerfile). This will install Clang 17.0.6 and Clang 18.1.8 (or newer), as well as the needed tools (such as CMake and Catch2).

## Building

Build the library with coverage information using

```bash
cmake --preset clang17-ninja-x86_64-coverage
cmake --build --preset clang17-ninja-x86_64-coverage
```

Note: there are other CMake presets defined as well.

## Evaluating the Coverage

First execute the unittests with

```bash
ctest --preset clang17-ninja-x86_64-coverage
```

Second, gather the coverage data with

```bash
llvm-profdata-17 merge -o unittest.profdata $(find build/clang17-ninja-x86_64-coverage -name "*.profraw")
```

Now it's time to present the information to the user with

```bash
llvm-cov-17 show build/clang17-ninja-x86_64-coverage/cov1/liblibcov1.so -instr-profile=unittest.profdata cov1/*.cpp -use-color --format html -output-dir=coverage_report_cov1 -coverage-watermark=95,75
llvm-cov-17 show build/clang17-ninja-x86_64-coverage/cov2/liblibcov2.so -instr-profile=unittest.profdata cov2/*.cpp -use-color --format html -output-dir=coverage_report_cov2 -coverage-watermark=95,75
llvm-cov-17 report build/clang17-ninja-x86_64-coverage/cov1/liblibcov1.so -instr-profile=unittest.profdata -use-color -show-region-summary=false
llvm-cov-17 report build/clang17-ninja-x86_64-coverage/cov2/liblibcov2.so -instr-profile=unittest.profdata -use-color -show-region-summary=false
```