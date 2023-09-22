// Copyright (c) 2023 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr/core.hpp>
#include <type_traits> // for std::is_same

struct A {
    const volatile int cv_value = 0;
    volatile int v_value = 0;
    const int c_value = 0;
    int value = 0;

    const volatile int& cv_ref;
    volatile int& v_ref;
    const int& c_ref;
    int& ref;

    const volatile int&& cv_rref;
    volatile int&& v_rref;
    const int&& c_rref;
    int&& rref;
};

int main() {
#if BOOST_PFR_USE_CPP17
    const volatile int cv_value = 0;
    volatile int v_value = 0;
    const int c_value = 0;
    int value = 0;

    typedef boost::pfr::detail::size_t_<12> fields_count_tag;

    {
        A a {cv_value, v_value, c_value, value,
             cv_value, v_value, c_value, value,
             std::move(cv_value), std::move(v_value), std::move(c_value), std::move(value)};

        const auto t = boost::pfr::detail::tie_as_tuple(a, fields_count_tag{});

        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<0>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<1>(t)), int volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<2>(t)), int const&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<3>(t)), int&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<4>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<5>(t)), int volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<6>(t)), int const&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<7>(t)), int&>());
        // FIXME implement rvalue references as a field support
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<8>(t)), int const volatile&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<9>(t)), int volatile&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<10>(t)), int const&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<11>(t)), int&&>());
    }

    {
        const A a {cv_value, v_value, c_value, value,
                   cv_value, v_value, c_value, value,
                   std::move(cv_value), std::move(v_value), std::move(c_value), std::move(value)};

        const auto t = boost::pfr::detail::tie_as_tuple(a, fields_count_tag{});

        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<0>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<1>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<2>(t)), int const&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<3>(t)), int const&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<4>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<5>(t)), int volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<6>(t)), int const&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<7>(t)), int&>());
        // FIXME implement rvalue references as a field support
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<8>(t)), int const volatile&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<9>(t)), int volatile&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<10>(t)), int const&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<11>(t)), int&&>());
    }

    {
        volatile A a {cv_value, v_value, c_value, value,
                      cv_value, v_value, c_value, value,
                      std::move(cv_value), std::move(v_value), std::move(c_value), std::move(value)};

        const auto t = boost::pfr::detail::tie_as_tuple(a, fields_count_tag{});

        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<0>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<1>(t)), int volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<2>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<3>(t)), int volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<4>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<5>(t)), int volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<6>(t)), int const&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<7>(t)), int&>());
        // FIXME implement rvalue references as a field support
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<8>(t)), int const volatile&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<9>(t)), int volatile&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<10>(t)), int const&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<11>(t)), int&&>());
    }

    {
        const volatile A a {cv_value, v_value, c_value, value,
                            cv_value, v_value, c_value, value,
                            std::move(cv_value), std::move(v_value), std::move(c_value), std::move(value)};

        const auto t = boost::pfr::detail::tie_as_tuple(a, fields_count_tag{});

        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<0>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<1>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<2>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<3>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<4>(t)), int const volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<5>(t)), int volatile&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<6>(t)), int const&>());
        static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<7>(t)), int&>());
        // FIXME implement rvalue references as a field support
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<8>(t)), int const volatile&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<9>(t)), int volatile&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<10>(t)), int const&&>());
        // static_assert(std::is_same<decltype(boost::pfr::detail::sequence_tuple::get<11>(t)), int&&>());
    }

#endif
}

