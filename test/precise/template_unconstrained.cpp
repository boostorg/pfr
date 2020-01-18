// Copyright (c) 2019-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <type_traits>

#include <boost/pfr/precise/core.hpp>

//#include <boost/multiprecision/cpp_dec_float.hpp>

//const int kPrecision = 18;
//using Numeric = boost::multiprecision::number<boost::multiprecision::cpp_dec_float<kPrecision>>;

template <class T>
struct unconstrained_template {
    unconstrained_template() = default;
    unconstrained_template(const unconstrained_template&) = default;
    unconstrained_template(unconstrained_template&&) = default;

    template <class U>
    constexpr unconstrained_template(const U& val)
        : value_{val}
    {}

    T value_{};
};

struct int_element {
    int value_;
};

struct aggregate_unconstrained {
    unconstrained_template<int> a;
    unconstrained_template<int_element> b;
//    Numeric c;
};

// TODO: WIP
int main() {
    using sanity = decltype(aggregate_unconstrained{
      boost::pfr::detail::ubiq_lref_constructor{0},
      boost::pfr::detail::ubiq_lref_constructor{1},
    });
    static_assert(
        std::is_same<
            sanity, aggregate_unconstrained
        >::value,
        "Precise reflection with template constructors sanity check fails"
    );

    boost::pfr::detail::enable_if_constructible_helper_t<aggregate_unconstrained, 2> foo;

    static_assert(
        std::is_same<
            boost::pfr::tuple_element_t<0, aggregate_unconstrained>,
            unconstrained_template<int>
        >::value,
        "Precise reflection with template constructors fails to work"
    );

    static_assert(
        std::is_same<
            boost::pfr::tuple_element_t<1, aggregate_unconstrained>,
            unconstrained_template<int_element>
        >::value,
        "Precise reflection with template constructors fails to work"
    );

    /*
    static_assert(
        std::is_same<
            boost::pfr::tuple_element_t<2, aggregate_unconstrained>,
            Numeric
        >::value,
        "Precise reflection with template constructors fails to work"
    );
    */

    aggregate_unconstrained aggr{3, 4};
    return boost::pfr::get<1>(aggr).value_.value_ - 4;
}
