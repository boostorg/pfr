// Copyright (c) 2016-2023 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core.hpp>

#include <boost/core/lightweight_test.hpp>

#include <tuple>
#include <type_traits>


template <class T, class U>
void test_get_matches_tuple(T x, U y) {
    const auto& x_cref = x;
    const auto& y_cref = y;

    BOOST_TEST_EQ(boost::pfr::get<0>(x), std::get<0>(y));
    BOOST_TEST_EQ(boost::pfr::get<1>(x),  std::get<1>(y));
    BOOST_TEST_EQ(boost::pfr::get<0>(x_cref),  std::get<0>(y_cref));
    BOOST_TEST_EQ(boost::pfr::get<1>(x_cref),  std::get<1>(y_cref));
    BOOST_TEST_EQ(boost::pfr::get<0>(std::move(x_cref)),  std::get<0>(std::move(y_cref)));
    BOOST_TEST_EQ(boost::pfr::get<1>(std::move(x_cref)),  std::get<1>(std::move(y_cref)));
    BOOST_TEST_EQ(boost::pfr::get<0>(std::move(x)),  std::get<0>(std::move(y)));
    BOOST_TEST_EQ(boost::pfr::get<1>(std::move(x)),  std::get<1>(std::move(y)));
    
    static_assert(std::is_same<decltype(boost::pfr::get<0>(x)), decltype(std::get<0>(y))>::value, "");
    static_assert(std::is_same<decltype(boost::pfr::get<1>(x)), decltype(std::get<1>(y))>::value, "");
    
    static_assert(std::is_same<decltype(boost::pfr::get<0>(x_cref)), decltype(std::get<0>(y_cref))>::value, "");
    static_assert(std::is_same<decltype(boost::pfr::get<1>(x_cref)), decltype(std::get<1>(y_cref))>::value, "");
    
    static_assert(std::is_same<decltype(boost::pfr::get<0>(std::move(x_cref))), decltype(std::get<0>(std::move(y_cref)))>::value, "");
    static_assert(std::is_same<decltype(boost::pfr::get<1>(std::move(x_cref))), decltype(std::get<1>(std::move(y_cref)))>::value, "");
    static_assert(std::is_same<decltype(boost::pfr::get<0>(std::move(x))), decltype(std::get<0>(std::move(y)))>::value, "");
    static_assert(std::is_same<decltype(boost::pfr::get<1>(std::move(x))), decltype(std::get<1>(std::move(y)))>::value, "");

    // TODO: seems to take a lot of effort with close to 0 profit
    //static_assert(std::is_same<boost::pfr::tuple_element_t<0, T>, std::tuple_element_t<0, U> >::value, "");
    //static_assert(std::is_same<boost::pfr::tuple_element_t<1, T>, std::tuple_element_t<1, U> >::value, "");
    //static_assert(std::is_same<boost::pfr::tuple_element_t<0, const T>, std::tuple_element_t<0, const U> >::value, "");
    //static_assert(std::is_same<boost::pfr::tuple_element_t<1, const T>, std::tuple_element_t<1, const U> >::value, "");
}

int main() {
#if BOOST_PFR_USE_CPP17
    struct aggregate { int first; char second; };
    struct aggregate_const { const int first; const char second; };

    test_get_matches_tuple(aggregate{1, 2}, std::tuple<int, char>{1, 2});
    test_get_matches_tuple(aggregate_const{1, 2}, std::tuple<const int, const char>{1, 2});

    int first = 1; char second;
    struct aggregate_ref { int& first; char& second; };
    struct aggregate_const_ref { const int& first; const char& second; };
    test_get_matches_tuple(
        aggregate_ref{first, second},
        std::tuple<int&, char&>{first, second}
    );
    test_get_matches_tuple(
        aggregate_const_ref{first, second},
        std::tuple<const int&, const char&>{first, second}
    );

    struct aggregate_rref { int&& first; char&& second; };
    struct aggregate_const_rref { const int&& first; const char&& second; };
    test_get_matches_tuple(
        aggregate_rref{std::move(first), std::move(second)},
        std::tuple<int&&, char&&>{std::move(first), std::move(second)}
    );
    test_get_matches_tuple(
        aggregate_const_rref{std::move(first), std::move(second)},
        std::tuple<const int&&, const char&&>{std::move(first), std::move(second)}
    );
#endif  // #if BOOST_PFR_USE_CPP17

    return boost::report_errors();
}

