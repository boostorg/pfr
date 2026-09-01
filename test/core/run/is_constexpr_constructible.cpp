// Copyright (c) 2025-2026 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/is_constexpr_default_constructible.hpp>

#include <string>

struct Yes {
    int a;
    double b;
    char c;
};

struct Yes2 {
    int a;
    double b;
    char c;
    Yes d[42];
};

class MyClass{
public:
    MyClass();
    ~MyClass();
};

struct No {
    int a;
    double b;
    char c;
    std::string str;
    MyClass mc;
};

int main() {
    static_assert(is_constexpr_default_constructible_v<Yes>, "");
    static_assert(is_constexpr_default_constructible_v<Yes2>, "");
    static_assert(!is_constexpr_default_constructible_v<No>, "");
}
