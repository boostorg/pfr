// Copyright (c) 2016-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Compile via:
// clang++-15 -std=c++20 -fmodule-file=pfr.pcm pfr.pcm example/module_usage.cpp

//[pfr_module_example
#include <cstdio>

import Boost.PFR;

struct some_person {
    const char* name;
    unsigned birth_year;
};

int main() {
    some_person val{"Edgar Allan Poe", 1809};
    std::puts(boost::pfr::get<0>(val));  // Writes "Edgar Allan Poe"
}
//]
