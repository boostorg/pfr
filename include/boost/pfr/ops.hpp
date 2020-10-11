// Copyright (c) 2016-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_OPS_HPP
#define BOOST_PFR_OPS_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/detail/detectors.hpp>
#include <boost/pfr/ops_fields.hpp>

/// \file boost/pfr/ops.hpp
/// Contains comparison operators and stream operators for types that do not have their own operators.
/// If type is comparable or streamable using it's own operator or it's conversion operator, then the original operator is used.
///
/// \b Requires: C++17 or \constexprinit{C++14 constexpr aggregate intializable type}.
///
/// \b Example:
/// \code
///     #include <boost/pfr/ops.hpp>
///     struct comparable_struct {      // No operators defined for that structure
///         int i; short s; char data[7]; bool bl; int a,b,c,d,e,f;
///     };
///     // ...
///
///     using namespace ops;
///
///     comparable_struct s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
///     comparable_struct s2 {0, 1, "Hello", false, 6,7,8,9,10,11111};
///     assert(s1 < s2);
///     std::cout << s1 << std::endl; // Outputs: {0, 1, H, e, l, l, o, , , 0, 6, 7, 8, 9, 10, 11}
/// \endcode
///
/// \podops for other ways to define operators and more details.
///
/// \b This \b header \b contains:
namespace boost { namespace pfr {

namespace detail {

///////////////////// Helper typedefs that are used by all the ops
    template <template <class, class> class Detector, class T>
    using enable_not_comp_base_t = typename std::enable_if<
        not_appliable<Detector, T const&, T const&>::value,
        bool
    >::type;

    template <template <class, class> class Detector, class T>
    using enable_comp_base_t = typename std::enable_if<
        !not_appliable<Detector, T const&, T const&>::value,
        bool
    >::type;
///////////////////// std::enable_if_t like functions that enable only if types do not support operation

    template <class T> using enable_not_eq_comp_t = enable_not_comp_base_t<comp_eq_detector, T>;
    template <class T> using enable_not_ne_comp_t = enable_not_comp_base_t<comp_ne_detector, T>;
    template <class T> using enable_not_lt_comp_t = enable_not_comp_base_t<comp_lt_detector, T>;
    template <class T> using enable_not_le_comp_t = enable_not_comp_base_t<comp_le_detector, T>;
    template <class T> using enable_not_gt_comp_t = enable_not_comp_base_t<comp_gt_detector, T>;
    template <class T> using enable_not_ge_comp_t = enable_not_comp_base_t<comp_ge_detector, T>;

///////////////////// std::enable_if_t like functions that enable only if types do support operation

    template <class T> using enable_eq_comp_t = enable_comp_base_t<comp_eq_detector, T>;
    template <class T> using enable_ne_comp_t = enable_comp_base_t<comp_ne_detector, T>;
    template <class T> using enable_lt_comp_t = enable_comp_base_t<comp_lt_detector, T>;
    template <class T> using enable_le_comp_t = enable_comp_base_t<comp_le_detector, T>;
    template <class T> using enable_gt_comp_t = enable_comp_base_t<comp_gt_detector, T>;
    template <class T> using enable_ge_comp_t = enable_comp_base_t<comp_ge_detector, T>;
} // namespace detail

template <class T>
detail::enable_not_eq_comp_t<T> eq(const T& lhs, const T& rhs) noexcept {
    return boost::pfr::eq_fields(lhs, rhs);
}

template <class T>
detail::enable_eq_comp_t<T> eq(const T& lhs, const T& rhs) noexcept {
    return lhs == rhs;
}

template <class T>
detail::enable_not_ne_comp_t<T> ne(const T& lhs, const T& rhs) noexcept {
    return boost::pfr::ne_fields(lhs, rhs);
}

template <class T>
detail::enable_ne_comp_t<T> ne(const T& lhs, const T& rhs) noexcept {
    return lhs != rhs;
}

template <class T>
detail::enable_not_lt_comp_t<T> lt(const T& lhs, const T& rhs) noexcept {
    return boost::pfr::lt_fields(lhs, rhs);
}

template <class T>
detail::enable_lt_comp_t<T> lt(const T& lhs, const T& rhs) noexcept {
    return lhs < rhs;
}

template <class T>
detail::enable_not_gt_comp_t<T> gt(const T& lhs, const T& rhs) noexcept {
    return boost::pfr::gt_fields(lhs, rhs);
}

template <class T>
detail::enable_gt_comp_t<T> gt(const T& lhs, const T& rhs) noexcept {
    return lhs > rhs;
}

template <class T>
detail::enable_not_le_comp_t<T> le(const T& lhs, const T& rhs) noexcept {
    return boost::pfr::le_fields(lhs, rhs);
}

template <class T>
detail::enable_le_comp_t<T> le(const T& lhs, const T& rhs) noexcept {
    return lhs <= rhs;
}

template <class T>
detail::enable_not_ge_comp_t<T> ge(const T& lhs, const T& rhs) noexcept {
    return boost::pfr::ge_fields(lhs, rhs);
}

template <class T>
detail::enable_ge_comp_t<T> ge(const T& lhs, const T& rhs) noexcept {
    return lhs >= rhs;
}

/// \brief helper function for Boost
template <class T>
static std::enable_if_t<std::is_trivial<T>::value, std::size_t> hash_value(const T& value) noexcept {
    return boost::pfr::hash_fields(value);
}

}} // namespace boost::pfr

#endif // BOOST_PFR_OPS_HPP
