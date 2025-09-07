// Copyright (c) 2020-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Detection of variadic structured binding support

#include <type_traits>

struct MyPair {
    int first;
    int second;
};

template <class T>
auto test() {
    const auto& [...x] = T{};
    return x...[0];
}

int main() {
    return ::test<MyPair>();
}
