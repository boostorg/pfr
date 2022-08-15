// Copyright (c) 2022 Denis Mikhailov

// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core.hpp>

struct A : boost::pfr::detail::guaranteed_nonreflectable
{};

int main() {
    (void)boost::pfr::tuple_size<A>::value; // Must be a compile time error
}

