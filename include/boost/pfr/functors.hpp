// Copyright (c) 2016-2020 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_FUNCTORS_HPP
#define BOOST_PFR_FUNCTORS_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/ops.hpp>

#include <boost/pfr/detail/functional.hpp>

/// \file boost/pfr/functors.hpp
/// Contains functors that are close to the Standard Library ones.
/// Each functor iterates over fields of the type.
///
/// \b Requires: C++17 or \constexprinit{C++14 constexpr aggregate intializable type}.
namespace boost { namespace pfr {

///////////////////// Comparisons

/// \brief std::equal_to like comparator
template <class T = void> struct equal_to {
    /// \return \b true if each field of \b x equals the field with same index of \b y.
    bool operator()(const T& x, const T& y) const {
        return boost::pfr::eq(x, y);
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
        return boost::pfr::eq(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::not_equal like comparator
template <class T = void> struct not_equal {
    /// \return \b true if at least one field \b x not equals the field with same index of \b y.
    bool operator()(const T& x, const T& y) const {
        return boost::pfr::ne(x, y);
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
        return boost::pfr::ne(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::greater like comparator
template <class T = void> struct greater {
    /// \return \b true if field of \b x greater than the field with same index of \b y and all previous fields of \b x equal to the same fields of \b y.
    bool operator()(const T& x, const T& y) const {
        return boost::pfr::gt(x, y);
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
        return boost::pfr::gt(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::less like comparator
template <class T = void> struct less {
    /// \return \b true if field of \b x less than the field with same index of \b y and all previous fields of \b x equal to the same fields of \b y.
    bool operator()(const T& x, const T& y) const {
        return boost::pfr::lt(x, y);
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
        return boost::pfr::lt(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::greater_equal like comparator
template <class T = void> struct greater_equal {
    /// \return \b true if field of \b x greater than the field with same index of \b y and all previous fields of \b x equal to the same fields of \b y;
    /// or if each field of \b x equals the field with same index of \b y.
    bool operator()(const T& x, const T& y) const {
        return boost::pfr::ge(x, y);
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
        return boost::pfr::ge(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::less_equal like comparator
template <class T = void> struct less_equal {
    /// \return \b true if field of \b x less than the field with same index of \b y and all previous fields of \b x equal to the same fields of \b y;
    /// or if each field of \b x equals the field with same index of \b y.
    bool operator()(const T& x, const T& y) const {
        return boost::pfr::le(x, y);
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
        return boost::pfr::le(x, y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond


/// \brief std::hash like functor
template <class T> struct hash {
    /// \return hash value of \b x.
    std::size_t operator()(const T& x) const {
        return boost::pfr::hash_value(x);
    }
};

}} // namespace boost::pfr

#endif // BOOST_PFR_FUNCTORS_HPP
