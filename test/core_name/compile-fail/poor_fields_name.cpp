// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#define BOOST_PFR_FUNCTION_SIGNATURE " *[field] "
#define BOOST_PFR_CORE_NAME_PARSING (3,2,"")
#include <boost/pfr/core_name.hpp>

#include <boost/core/lightweight_test.hpp>

struct A { int field; };

int main() {
    BOOST_TEST_EQ( (boost::pfr::get_name<0,A>()), "field");

    return boost::report_errors();
}


