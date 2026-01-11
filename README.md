# zenithcpp-tools

**ZENITH Constexpr Tools — C++23 Edition**  
Pure compile-time power for modern C++.

Safe, bounded, constexpr-friendly STL alternatives and utilities. Designed for zero-overhead, compile-time safety in performance-critical and security-sensitive code.

Built by **zenithcpp** — January 2026.

[![MIT License](https://img.shields.io/badge/License-MIT-green.svg)](LICENSE)
[![C++23](https://img.shields.io/badge/C++-23-blue.svg)](https://en.cppreference.com/w/cpp/23)
[![Header Only](https://img.shields.io/badge/Header-Only-brightgreen.svg)]()
[![Cppcheck Clean](https://img.shields.io/badge/Cppcheck-Clean-success.svg)]()

## Features

- `constexpr_vector.hpp` — Bounded, constexpr-compatible vector with fixed capacity (no dynamic allocation).
- `constexpr_string_view.hpp` — Enhanced constexpr string view utilities.
- `constexpr_parser_toolkit.hpp` — Lightweight compile-time parsing helpers.
- `allocator.hpp` — Safe, customizable constexpr allocator.
- `security/discipline.hpp` — Compile-time security policies and checks.

All components are **header-only**, **zero-dependency**, and fully constexpr where possible.

## Quick Start

```cpp
#include "zenith/constexpr_vector.hpp"

constexpr zenith::constexpr_vector<int, 16> v = {1, 2, 3, 4};
static_assert(v.size() == 4);
static_assert(v[2] == 3

**Directory Structure
zenithcpp-tools/
├── include/zenith/
│   ├── constexpr_vector.hpp
│   ├── constexpr_string_view.hpp
│   ├── constexpr_parser_toolkit.hpp
│   ├── allocator.hpp
│   └── security/
│       └── discipline.hpp
├── examples/          # Usage demonstrations
├── tests/             # Comprehensive test suite
├── LICENSE            # MIT License
└── README.md
Build & Run Tests
Header-only library — no build required.
Compile and run tests (Clang/GCC 14+ recommended for full C++23 support):
# Basic tests
clang++ -std=c++23 -I include tests/basic/*.cpp -o test_basic
./test_basic

# All tests
find tests -name "*.cpp" | xargs clang++ -std=c++23 -I include -o all_tests
./all_tests
Related Project

constexpr-eval — Full constexpr arithmetic expression evaluator built with these tools.

Contributing
Contributions welcome! Open issues or PRs for:

New constexpr utilities
Performance improvements
Additional safety checks
Better documentation/examples

License
MIT License — free to use, modify, and distribute.
BTC Blockchain Timestamp
ZENITH — Pushing C++ compile-time boundaries safely.
zenithcpp — January 2026


