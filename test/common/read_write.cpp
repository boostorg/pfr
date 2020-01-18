// Copyright (c) 2016-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/core/lightweight_test.hpp>
#include <sstream>
#include <string>


#ifdef BOOST_PFR_TEST_FLAT
#include <boost/pfr/flat/io.hpp>

namespace boost { namespace test {
    template <class Char, class Traits, class T>
    void read(std::basic_istream<Char, Traits>& in, T& value) {
        ::boost::pfr::flat_read(in, value);
    }

    template <class Char, class Traits, class T>
    void write(std::basic_ostream<Char, Traits>& out, const T& value) {
        ::boost::pfr::flat_write(out, value);
    }
}}

#endif

#ifdef BOOST_PFR_TEST_PRECISE
#include <boost/pfr/precise/io.hpp>
namespace boost { namespace test {
    using boost::pfr::read;
    using boost::pfr::write;
}}
#endif




template <class T>
void test_write_read(const T& value) {
    T result;
    std::stringstream ss;
    boost::test::write(ss, value);
    boost::test::read(ss, result);
    BOOST_TEST_EQ(value.f0, result.f0);
    BOOST_TEST_EQ(value.f1, result.f1);
    BOOST_TEST_EQ(value.f2, result.f2);
    BOOST_TEST_EQ(value.f3, result.f3);
    BOOST_TEST_EQ(value.f4, result.f4);
}

template <class T>
void to_string_test(const T& value, const char* ethalon) {
    std::stringstream ss;
    boost::test::write(ss, value);
    BOOST_TEST_EQ(ss.str(), ethalon);
}

template <class T>
void test_type(const T& value, const char* ethalon) {
    test_write_read(value);
    to_string_test(value, ethalon);
}



struct with_operator{};
inline bool operator==(with_operator, with_operator) {
    return true;
}
std::ostream& operator<<(std::ostream& os, with_operator) {
    return os << "{with_operator}";
}
std::istream& operator>>(std::istream& is, with_operator&) {
    std::string s;
    is >> s;
    return is;
}

int main() {
    struct test1 {
        int f0;
        int f1;
        char f2;
        int f3;
        short f4;
    };
    test_type(test1{1, 2, '3', 4, 5}, "{1, 2, 3, 4, 5}");
    test_type(test1{199, 299, '9', 499, 599}, "{199, 299, 9, 499, 599}");

#ifdef BOOST_PFR_TEST_PRECISE
    struct test2 {
        with_operator f0;
        with_operator f1;
        with_operator f2;
        with_operator f3;
        with_operator f4;
    };
    test_type(test2{}, "{{with_operator}, {with_operator}, {with_operator}, {with_operator}, {with_operator}}");

    struct test3 {
        int f0;
        int f1;
        char f2;
        int f3;
        with_operator f4;
    };

    test_type(
        test3{1, 2, '3', 4, {}},
        "{1, 2, 3, 4, {with_operator}}"
    );

#if (BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE) \
    && !defined(_MSC_VER) /* TODO: remove after fixing strange errors https://ci.appveyor.com/project/apolukhin/magic-get/build/1.65.108-develop */
    struct test4 {
        int f0;
        std::string f1;
        char f2;
        int f3;
        std::string f4;
    };
    test_type(
        test4{1, {"my o my"}, '3', 4, {"hello there!"} },
        "{1, \"my o my\", 3, 4, \"hello there!\"}"
    );

    #if 0
    // TODO:
    std::string f1_referenced{"my O my"};
    std::string f4_referenced{"Hello There!"};
    struct test5 {
        int f0;
        const std::string& f1;
        char f2;
        int f3;
        const std::string& f4;
    };
    to_string_test(
        test5{1, f1_referenced, '3', 4, f4_referenced },
        "{1, \"my o my\", 3, 4, \"hello there!\"}"
    );
    #endif
#endif
#endif // BOOST_PFR_TEST_PRECISE

    return boost::report_errors();
}


