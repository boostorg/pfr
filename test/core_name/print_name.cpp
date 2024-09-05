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
#ifndef BOOST_PFR_CORE_NAME_PARSING
#define BOOST_PFR_CORE_NAME_PARSING (0,0,"")
#endif

#include <boost/pfr/core_name.hpp>

namespace user_defined_namespace {
    struct user_defined_class { int user_defined_field; };
}

using namespace boost::pfr;

// Cloned from core_name20_static.hpp but removed the sanity check
template <class T, std::size_t I>
inline constexpr auto no_check_stored_name_of_field = detail::name_of_field_impl<T,
    detail::make_clang_wrapper(std::addressof(detail::sequence_tuple::get<I>(
        detail::tie_as_tuple(detail::fake_object<T>())
    )))
>();

int main()
{
    std::cout << "user_defined_namespace::user_defined_class::user_defined_field: "
        << no_check_stored_name_of_field<user_defined_namespace::user_defined_class, 0>.data() << '\n';


    return 0;
}

