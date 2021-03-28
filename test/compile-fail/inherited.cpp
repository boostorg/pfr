// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core.hpp>
#include <boost/core/lightweight_test.hpp>

struct A
{};

struct B : A
{
    int one;
    int two;
};

int main() {
#ifndef __cpp_lib_is_aggregate
// TODO: No known way to detect inherited
#   error No known way to detect inherited.
#endif
    (void)boost::pfr::tuple_size<B>::value; // Must be a compile time error
    return boost::report_errors();
}



