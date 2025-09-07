// Copyright (c) 2020-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Detection of variadic structured binding support

#include <type_traits>

struct my_pair {
    int i;
    short s;
};

int main() {
   const auto& [...elements] = my_pair{1, 2};
   static_assert( sizeof...(elements) == 2);
}
