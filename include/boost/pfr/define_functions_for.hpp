// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <boost/pfr/functors.hpp>

/// \file boost/pfr/global_pod_ops.hpp
/// Contains comparison operators and stream operators for any POD types that do not have their own operators.
/// If POD is comparable or streamable using it's own operator or it's conversion operator, then the original operator is used.
///
/// \b Example:
/// \code
///     struct comparable_struct {      // No operators defined for that structure
///         int i; short s; char data[7]; bool bl; int a,b,c,d,e,f;
///     };
///     using namespace pod_ops;
///
///     comparable_struct s1 {0, 1, "Hello", false, 6,7,8,9,10,11};
///     comparable_struct s2 {0, 1, "Hello", false, 6,7,8,9,10,11111};
///     assert(s1 < s2);
///     std::cout << s1 << std::endl; // Outputs: {0, 1, H, e, l, l, o, , , 0, 6, 7, 8, 9, 10, 11}
/// \endcode
///
/// \see boost/pfr/global_pod_ops.hpp for a more aggressive way to define operators.


#define BOOST_PFR_DEFINE_FUNCTIONS_FOR(T)                                                                                   \
    inline bool operator==(const T& lhs, const T& rhs) noexcept { return ::boost::pfr::flat_equal_to<T>{}(lhs, rhs);      } \
    inline bool operator!=(const T& lhs, const T& rhs) noexcept { return ::boost::pfr::flat_not_equal<T>{}(lhs, rhs);     } \
    inline bool operator< (const T& lhs, const T& rhs) noexcept { return ::boost::pfr::flat_less<T>{}(lhs, rhs);          } \
    inline bool operator> (const T& lhs, const T& rhs) noexcept { return ::boost::pfr::flat_greater<T>{}(lhs, rhs);       } \
    inline bool operator<=(const T& lhs, const T& rhs) noexcept { return ::boost::pfr::flat_less_equal<T>{}(lhs, rhs);    } \
    inline bool operator>=(const T& lhs, const T& rhs) noexcept { return ::boost::pfr::flat_greater_equal<T>{}(lhs, rhs); } \
    template <class Char, class Traits>                                                                                     \
    ::std::basic_ostream<Char, Traits>& operator<<(::std::basic_ostream<Char, Traits>& out, const T& value) {               \
        ::boost::pfr::flat_write(out, value);                                                                               \
        return out;                                                                                                         \
    }                                                                                                                       \
    template <class Char, class Traits>                                                                                     \
    ::std::basic_istream<Char, Traits>& operator>>(::std::basic_istream<Char, Traits>& in, T& value) {                      \
        ::boost::pfr::flat_read(in, value);                                                                                 \
        return in;                                                                                                          \
    }                                                                                                                       \
    std::size_t hash_value(const T& v) noexcept {                                                                           \
        return ::boost::pfr::flat_hash<T>{}(v);                                                                             \
    }                                                                                                                       \
/**/


