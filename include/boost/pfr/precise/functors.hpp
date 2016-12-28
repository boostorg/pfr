// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_PRECISE_FUNCTORS_HPP
#define BOOST_PFR_PRECISE_FUNCTORS_HPP

#pragma once

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <boost/pfr/detail/functional.hpp>
#include <boost/pfr/flat/core.hpp>

/// \file boost/pfr/functors.hpp
/// Contains functors that are close to the Standard Library ones.
/// Each functor iterates over fields of the type.

namespace boost { namespace pfr {

namespace detail {

    template <template <std::size_t, std::size_t> class Visitor, class T, class U>
    bool binary_visit(const T& x, const U& y) {
        constexpr std::size_t fields_count_lhs = detail::fields_count<std::remove_reference_t<T>>();
        constexpr std::size_t fields_count_rhs = detail::fields_count<std::remove_reference_t<U>>();
        constexpr std::size_t fields_count_min = detail::min_size(fields_count_lhs, fields_count_rhs);
        typedef Visitor<0, fields_count_min> visitor_t;

#if __cplusplus >= 201606L /* Oulu meeting, not the exact value */
        return visitor_t::cmp(detail::as_tuple(x), detail::as_tuple(y));
#else
        bool result = true;
        ::boost::pfr::detail::for_each_field_dispatcher(
            x,
            [&result, &y](const auto& lhs) {
                ::boost::pfr::detail::for_each_field_dispatcher(
                    y,
                    [&result, &lhs](const auto& rhs) {
                        result = visitor_t::cmp(lhs, rhs);
                    },
                    std::make_index_sequence<fields_count_rhs>{}
                );
            },
            std::make_index_sequence<fields_count_lhs>{}
        );

        return result;
#endif
    }

} // namespace detail

///////////////////// Comparisons

/// \brief std::equal_to like comparator
template <class T = void> struct equal_to {
    /// \return \b true if each field of \b x equals the field with same index of \b y
    bool operator()(const T& x, const T& y) const {
        return detail::binary_visit<detail::equal_impl>(x, y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const;
#endif
};

/// @cond
template <> struct equal_to<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const {
        return detail::binary_visit<detail::equal_impl>(x, y);
    }

};
/// @endcond

/// \brief std::not_equal like comparator
template <class T = void> struct not_equal {
    /// \return \b true if at least one field \b x not equals the field with same index of \b y
    bool operator()(const T& x, const T& y) const {
        return detail::binary_visit<detail::not_equal_impl>(x, y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const;
#endif
};

/// @cond
template <> struct not_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const {
        return detail::binary_visit<detail::not_equal_impl>(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::greater like comparator
template <class T = void> struct greater {
    /// \return \b true if field of \b x greater than the field with same index of \b y and all previous fields of \b x eqeal to the same fields of \b y
    bool operator()(const T& x, const T& y) const {
        return detail::binary_visit<detail::greater_impl>(x, y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const;
#endif
};

/// @cond
template <> struct greater<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const {
        return detail::binary_visit<detail::greater_impl>(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::less like comparator
template <class T = void> struct less {
    /// \return \b true if field of \b x less than the field with same index of \b y and all previous fields of \b x eqeal to the same fields of \b y
    bool operator()(const T& x, const T& y) const {
        return detail::binary_visit<detail::less_impl>(x, y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const;
#endif
};

/// @cond
template <> struct less<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const {
        return detail::binary_visit<detail::less_impl>(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::greater_equal like comparator
template <class T = void> struct greater_equal {
    /// \return \b true if field of \b x greater than the field with same index of \b y and all previous fields of \b x eqeal to the same fields of \b y;
    /// or if each field of \b x equals the field with same index of \b y .
    bool operator()(const T& x, const T& y) const {
        return detail::binary_visit<detail::greater_equal_impl>(x, y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const;
#endif
};

/// @cond
template <> struct greater_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const {
        return detail::binary_visit<detail::greater_equal_impl>(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::less_equal like comparator
template <class T = void> struct less_equal {
    /// \return \b true if field of \b x less than the field with same index of \b y and all previous fields of \b x eqeal to the same fields of \b y;
    /// or if each field of \b x equals the field with same index of \b y .
    bool operator()(const T& x, const T& y) const {
        return detail::binary_visit<detail::less_equal_impl>(x, y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const;
#endif
};

/// @cond
template <> struct less_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const {
        return detail::binary_visit<detail::less_equal_impl>(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond


/// \brief std::hash like functor
template <class T> struct hash {
    /// \return hash value of \b x
    std::size_t operator()(const T& x) const {
        constexpr std::size_t fields_count = detail::fields_count<std::remove_reference_t<T>>();
#if __cplusplus >= 201606L /* Oulu meeting, not the exact value */
        return detail::hash_impl<0, fields_count>::compute(detail::as_tuple(x));
#else
        std::size_t result = 0;
        ::boost::pfr::detail::for_each_field_dispatcher(
            x,
            [&result](const auto& lhs) {
                result = detail::hash_impl<0, fields_count>::compute(lhs);
            },
            std::make_index_sequence<fields_count>{}
        );

        return result;
#endif
    }
};

}} // namespace boost::pfr

#endif // BOOST_PFR_PRECISE_FUNCTORS_HPP
