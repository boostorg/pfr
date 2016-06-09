// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <boost/pfr/functors.hpp>

namespace boost { namespace pfr { namespace detail {

    template <class T, class U>
    using enable_comparisons = std::enable_if_t<
        std::is_same<T, U>::value && std::is_pod<T>::value,
        bool
    >;

}}} // namespace boost::pfr::detail

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    template <class T> bool operator==(const T& lhs, const T& rhs) noexcept;
    template <class T> bool operator!=(const T& lhs, const T& rhs) noexcept;
    template <class T> bool operator< (const T& lhs, const T& rhs) noexcept;
    template <class T> bool operator> (const T& lhs, const T& rhs) noexcept;
    template <class T> bool operator<=(const T& lhs, const T& rhs) noexcept;
    template <class T> bool operator>=(const T& lhs, const T& rhs) noexcept;

    template <class Char, class Traits, class T>
    std::basic_ostream<Char, Traits>& operator<<(std::basic_ostream<Char, Traits>& out, const T& value);

    template <class Char, class Traits, class T>
    std::basic_istream<Char, Traits>& operator>>(std::basic_istream<Char, Traits>& in, T& value);

    /// \brief helper function for Boost
    template <class T> std::size_t hash_value(const T& value) noexcept;
#else
    template <class T, class U>
    static boost::pfr::detail::enable_comparisons<T, U> operator==(const T& lhs, const U& rhs) noexcept {
        return ::boost::pfr::flat_equal_to<T>{}(lhs, rhs);
    }

    template <class T, class U>
    static boost::pfr::detail::enable_comparisons<T, U> operator!=(const T& lhs, const U& rhs) noexcept {
        return ::boost::pfr::flat_not_equal<T>{}(lhs, rhs);
    }

    template <class T, class U>
    static boost::pfr::detail::enable_comparisons<T, U> operator<(const T& lhs, const U& rhs) noexcept {
        return ::boost::pfr::flat_less<T>{}(lhs, rhs);
    }

    template <class T, class U>
    static boost::pfr::detail::enable_comparisons<T, U> operator>(const T& lhs, const U& rhs) noexcept {
        return ::boost::pfr::flat_greater<T>{}(lhs, rhs);
    }

    template <class T, class U>
    static boost::pfr::detail::enable_comparisons<T, U> operator<=(const T& lhs, const U& rhs) noexcept {
        return ::boost::pfr::flat_less_equal<T>{}(lhs, rhs);
    }

    template <class T, class U>
    static boost::pfr::detail::enable_comparisons<T, U> operator>=(const T& lhs, const U& rhs) noexcept {
        return ::boost::pfr::flat_greater_equal<T>{}(lhs, rhs);
    }

    template <class Char, class Traits, class T>
    static std::enable_if_t<std::is_pod<T>::value, std::basic_ostream<Char, Traits>&> operator<<(std::basic_ostream<Char, Traits>& out, const T& value) {
        ::boost::pfr::flat_write(out, value);
        return out;
    }

    template <class Char, class Traits, class T>
    static std::enable_if_t<std::is_pod<T>::value, std::basic_istream<Char, Traits>&> operator>>(std::basic_istream<Char, Traits>& in, T& value) {
        ::boost::pfr::flat_read(in, value);
        return in;
    }

    template <class T>
    static std::enable_if_t<std::is_pod<T>::value, std::size_t> hash_value(const T& value) noexcept {
        return ::boost::pfr::flat_hash<T>{}(value);
    }
#endif
