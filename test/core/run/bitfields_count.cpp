// Copyright (c) 2016-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/tuple_size.hpp>

#include <cstdint>

struct bf7 {
    uint8_t b0 : 1;
    uint8_t b1 : 1;
    uint8_t b2 : 1;
    uint8_t b3 : 1;
    uint8_t b4 : 1;
    uint8_t b5 : 1;
    uint8_t b6 : 1;
};
static_assert(sizeof(bf7) == 1, "");

struct bf8 {
    uint8_t b0 : 1;
    uint8_t b1 : 1;
    uint8_t b2 : 1;
    uint8_t b3 : 1;
    uint8_t b4 : 1;
    uint8_t b5 : 1;
    uint8_t b6 : 1;
    uint8_t b7 : 1;
};
static_assert(sizeof(bf8) == 1, "");

struct bf16 {
    uint8_t b0 : 1;
    uint8_t b1 : 1;
    uint8_t b2 : 1;
    uint8_t b3 : 1;
    uint8_t b4 : 1;
    uint8_t b5 : 1;
    uint8_t b6 : 1;
    uint8_t b7 : 1;
    uint8_t b8 : 1;
    uint8_t b9 : 1;
    uint8_t b10 : 1;
    uint8_t b11 : 1;
    uint8_t b12 : 1;
    uint8_t b13 : 1;
    uint8_t b14 : 1;
    uint8_t b15 : 1;
};
static_assert(sizeof(bf16) == 2, "");

struct bf24 {
    uint8_t b0 : 1;
    uint8_t b1 : 1;
    uint8_t b2 : 1;
    uint8_t b3 : 1;
    uint8_t b4 : 1;
    uint8_t b5 : 1;
    uint8_t b6 : 1;
    uint8_t b7 : 1;
    uint8_t b8 : 1;
    uint8_t b9 : 1;
    uint8_t b10 : 1;
    uint8_t b11 : 1;
    uint8_t b12 : 1;
    uint8_t b13 : 1;
    uint8_t b14 : 1;
    uint8_t b15 : 1;
    uint8_t b16 : 1;
    uint8_t b17 : 1;
    uint8_t b18 : 1;
    uint8_t b19 : 1;
    uint8_t b20 : 1;
    uint8_t b21 : 1;
    uint8_t b22 : 1;
    uint8_t b23 : 1;
};
static_assert(sizeof(bf24) == 3, "");

int main() {
    static_assert(boost::pfr::tuple_size_v<bf7> == 7, "");
    static_assert(boost::pfr::tuple_size_v<bf8> == 8, "");
    static_assert(boost::pfr::tuple_size_v<bf16> == 16, "");
    static_assert(boost::pfr::tuple_size_v<bf24> == 24, "");
}
