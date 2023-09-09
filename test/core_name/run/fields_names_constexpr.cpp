// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#include <boost/pfr/core_name.hpp>

#include <functional>
#include <string>

struct nonconstexpr {
    nonconstexpr() {};
};

struct Aggregate {
    int member1;
    nonconstexpr this_is_a_name;
    std::reference_wrapper<char> c;
    std::string Forth;
};

static_assert(boost::pfr::get_name<0, Aggregate>() == "member1");
static_assert(boost::pfr::get_name<1, Aggregate>() == "this_is_a_name");
static_assert(boost::pfr::get_name<2, Aggregate>() == "c");
static_assert(boost::pfr::get_name<3, Aggregate>() == "Forth");

static_assert(boost::pfr::names_as_array<Aggregate>() == std::array<std::string_view, 4>{
        "member1",
        "this_is_a_name",
        "c",
        "Forth"
});

int main() {}

