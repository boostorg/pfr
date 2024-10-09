// Copyright (c) 2023-2024 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/tuple_size.hpp>

struct A {
    template <typename... Args>
    explicit A(Args&&...) {}
};

int main() {
    (void)boost::pfr::tuple_size<A>::value; // Must be a compile time error
}
