// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifdef BOOST_PFR_TEST_PRECISE
#   include <boost/pfr/precise/core.hpp>
#   define BOOST_PFR_TEST_FUNCTION(x) boost::pfr::get<I>(x)
#elif defined(BOOST_PFR_TEST_FLAT)
#   include <boost/pfr/flat/core.hpp>
#   define BOOST_PFR_TEST_FUNCTION(x) boost::pfr::flat_get<I>(x)
#else
#   error Misused test
#endif

#include <boost/core/lightweight_test.hpp>

namespace helper {
    template <std::size_t I, class T>
    decltype(auto) get(T&& v) {
        return BOOST_PFR_TEST_FUNCTION(std::forward<T>(v));
    }
}

int main() {
    using namespace std;
    using namespace helper;
    struct foo { int i; short s;};

    foo f{1, 2};
    BOOST_TEST_EQ(get<0>(f), 1);

    const foo cf{1, 2};
    BOOST_TEST_EQ(get<1>(cf), 2);

    std::tuple<int, short> t{10, 20};
    BOOST_TEST_EQ(get<0>(t), 10);

    const std::tuple<int, short> ct{10, 20};
    BOOST_TEST_EQ(get<1>(ct), 20);

    return boost::report_errors();
}

