// Copyright (c) 2023 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core_memptr.hpp>

#pragma pack(1)
struct Foo
{
    char ch;
    short id;
    short opt;
    int value;
};

int main() {
	(void)boost::pfr::get_memptr<3>(boost::pfr::type_identity<Foo>{}); // Must be a compile time error
}

