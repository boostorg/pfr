// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core_memptr.hpp>
#include <boost/core/lightweight_test.hpp>

struct Foo
{
    char ch;
    short id;
    short opt;
    int value;
};

int main() {

    auto ch_memptr = boost::pfr::get_memptr<0>(boost::pfr::type_identity<Foo>{});
    auto id_memptr = boost::pfr::get_memptr<1>(boost::pfr::type_identity<Foo>{});
    auto opt_memptr = boost::pfr::get_memptr<2>(boost::pfr::type_identity<Foo>{});
    auto value_memptr = boost::pfr::get_memptr<3>(boost::pfr::type_identity<Foo>{});

    BOOST_TEST_EQ(ch_memptr, &Foo::ch);
    BOOST_TEST_EQ(id_memptr, &Foo::id);
    BOOST_TEST_EQ(opt_memptr, &Foo::opt);
    BOOST_TEST_EQ(value_memptr, &Foo::value);

    auto obj = Foo{};

    obj.*ch_memptr = 'c';
    obj.*id_memptr = 100;
    obj.*opt_memptr = 200;
    obj.*value_memptr = 3000;

    BOOST_TEST_EQ(obj.ch, 'c');
    BOOST_TEST_EQ(obj.id, 100);
    BOOST_TEST_EQ(obj.opt, 200);
    BOOST_TEST_EQ(obj.value, 3000);

    return boost::report_errors();
}
