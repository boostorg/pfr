// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#include <iostream>

// This cpp file:
// * tests BOOST_PFR_CORE_NAME_PARSING macro
// * outputs full name of the function so that PFRs extraction of field name could be adjust to new compiler without requesting regression tester's help
#define BOOST_PFR_CORE_NAME_PARSING (0,0,false,"")
#include <boost/pfr/core_name.hpp>

namespace user_defined_namespace {
    struct user_defined_class { int user_defined_field; };
}

int main()
{
    using namespace boost::pfr;

    std::cout << "user_defined_namespace::user_defined_class::user_defined_field: "
        << get_name<0, user_defined_namespace::user_defined_class>() << '\n';


    return 0;
}

