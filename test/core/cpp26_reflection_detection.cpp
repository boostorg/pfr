// Copyright (c) 2025-2026 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Detection of C++26 Reflection

#include <type_traits>
#include <version>

#ifndef __cpp_lib_reflection
#error Compiler does not support the required features
#endif

#include <meta>

struct MyPair {
    int first;
    int second;
};

template <class T>
auto test() {
    return T{}.[:
        nonstatic_data_members_of(
            ^^T,
            std::meta::access_context::current()
        ).at(0)
    :];
}

int main() {
    return ::test<MyPair>();
}

