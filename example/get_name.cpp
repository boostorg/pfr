// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#include <boost/pfr/config.hpp>

#if BOOST_PFR_ENABLE_GET_NAME_STATIC && BOOST_PFR_USE_CPP17
//[pfr_example_get_name
/*`
    Since C++20 it's possible to read name of structure fields by index using Boost.PFR library.
    The following example shows how to do it using [funcref boost::pfr::get_name].

    Let's define some structure:
*/
#include <boost/pfr/core_name.hpp>

struct foo {            // defining structure
    int some_integer;
    char c;
};

/*`
    We can access field's names of that structure by index:
*/
constexpr auto r1 = boost::pfr::get_name<0, foo>(); // reading name of field with index 0, returns string `some_integer`
constexpr auto r2 = boost::pfr::get_name<1, foo>(); // reading name of field with index 1, returns string `c`
//] [/pfr_example_get_name]
#endif

int main() {
#if BOOST_PFR_ENABLE_GET_NAME_STATIC && BOOST_PFR_USE_CPP17
    if (r1 != "some_integer") return 1;
    if (r2 != "c") return 2;
#endif

    return 0;
}