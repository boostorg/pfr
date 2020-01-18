// Copyright (c) 2016-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/flat/core.hpp>

int main() {
    struct foo { int i; char c;};
    static_assert(boost::pfr::flat_tuple_size_v<foo> == 2, "");
}

