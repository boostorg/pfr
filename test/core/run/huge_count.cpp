// Copyright (c) 2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/detail/tuple_size.hpp>

#include <climits>
#include <cstdint>

#if defined(__clang__)
#define ARRAY_MAX (SIZE_MAX >> 3)
#define OBJECT_MAX SIZE_MAX
#elif defined(__GNUC__)
#define ARRAY_MAX INT_MAX
#define OBJECT_MAX SIZE_MAX
#else  // defined(_MSC_VER)
#define ARRAY_MAX INT_MAX
#define OBJECT_MAX INT_MAX
#endif

struct A
{
    char x[ARRAY_MAX <= (OBJECT_MAX >> 3) ? ARRAY_MAX : OBJECT_MAX >> 3];
};

struct B
{
    A a;
    A b;
    A c;
    A d;
    A e;
    A f;
    A g;
    A h;
};

struct C
{
    A& a;
    A b;
    A c;
    A d;
    A e;
    A f;
    A g;
    A h;
};

int main() {
#ifndef _MSC_VER
    static_assert(boost::pfr::tuple_size_v<char[ARRAY_MAX]> == ARRAY_MAX, "");
#endif
    static_assert(boost::pfr::tuple_size_v<B> == 8, "");
    static_assert(boost::pfr::tuple_size_v<C> == 8, "");
}
