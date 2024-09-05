// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#include <boost/pfr/config.hpp>

#if BOOST_PFR_CORE_NAME_ENABLED && BOOST_PFR_USE_CPP17
//[pfr_example_get_name
/*`
    Since C++20 it's possible to read name of a structure field by index using Boost.PFR library.
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
constexpr std::string_view n1 = boost::pfr::get_name<0, foo>(); // returns "some_integer"
constexpr std::string_view n2 = boost::pfr::get_name<1, foo>(); // returns "c"
//] [/pfr_example_get_name]
#endif

int main() {
#if BOOST_PFR_CORE_NAME_ENABLED && BOOST_PFR_USE_CPP17
    if (n1 != "some_integer") return 1;
    if (n2 != "c") return 2;
#endif

    return 0;
}
