// Copyright (c) 2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/tuple_size.hpp>

#include <climits>
#include <cstdint>

#if defined(__clang__)
#   if SIZE_MAX > (1ULL << 32) - 1
#       define ARRAY_MAX (SIZE_MAX >> 3)
#   else
#       define ARRAY_MAX SIZE_MAX
#   endif
#   define OBJECT_MAX SIZE_MAX
#elif defined(__GNUC__)
#   define ARRAY_MAX INT_MAX
#   define OBJECT_MAX (SIZE_MAX >> 1)
#elif defined(_MSC_VER)
#   define ARRAY_MAX INT_MAX
#   define OBJECT_MAX UINT_MAX
#else  // Let's play it safe
#   define ARRAY_MAX INT_MAX
#   define OBJECT_MAX INT_MAX
#endif

#pragma pack(1)
struct A {
    char x[ARRAY_MAX <= (OBJECT_MAX >> 3) ? ARRAY_MAX : OBJECT_MAX >> 3];
};

struct B {
    A a;
    A b;
    A c;
    A d;
    A e;
    A f;
    A g;
    A h;
};

struct C {
    A& a;
    A b;
    A c;
    A d;
    A e;
    A f;
    A g;
    A h;
};
#pragma pack()

int main() {
#ifndef _MSC_VER
    static_assert(boost::pfr::tuple_size_v<char[ARRAY_MAX]> == ARRAY_MAX, "");
#endif
    static_assert(boost::pfr::tuple_size_v<B> == 8, "");
    static_assert(boost::pfr::tuple_size_v<C> == 8, "");
}
