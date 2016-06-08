// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#pragma once

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <boost/pfr/core.hpp>

namespace boost { namespace pfr {

namespace detail {
    template <std::size_t I, std::size_t N>
    struct equal_impl {
        template <class T, class U>
        static bool cmp(const T& v1, const U& v2) noexcept {
            return ::boost::pfr::get<I>(v1) == ::boost::pfr::get<I>(v2)
                && equal_impl<I + 1, N>::cmp(v1, v2);
        }
    };

    template <std::size_t N>
    struct equal_impl<N, N> {
        template <class T, class U>
        static bool cmp(const T&, const U&) noexcept {
            return flat_tuple_size_v<T> == flat_tuple_size_v<U>;
        }
    };

    template <std::size_t I, std::size_t N>
    struct less_impl {
        template <class T, class U>
        static bool cmp(const T& v1, const U& v2) noexcept {
            return ::boost::pfr::get<I>(v1) < ::boost::pfr::get<I>(v2)
                || (::boost::pfr::get<I>(v1) == ::boost::pfr::get<I>(v2) && less_impl<I + 1, N>::cmp(v1, v2));
        }
    };

    template <std::size_t N>
    struct less_impl<N, N> {
        template <class T, class U>
        static bool cmp(const T&, const U&) noexcept {
            return flat_tuple_size_v<T> < flat_tuple_size_v<U>;
        }
    };

    template <typename SizeT>
    inline void hash_combine(SizeT& seed, SizeT value) noexcept {
        seed ^= value + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    template <std::size_t I, std::size_t N>
    struct hash_impl {
        template <class T>
        static std::size_t compute(const T& val) noexcept {
            std::size_t h = std::hash< flat_tuple_element_t<I, T> >()( ::boost::pfr::get<I>(val) );
            hash_combine(h, hash_impl<I + 1, N>::compute(val) );
            return h;
        }
    };

    template <std::size_t N>
    struct hash_impl<N, N> {
        template <class T>
        static std::size_t compute(const T&) noexcept {
            return 0;
        }
    };

///////////////////// Define min_element and to avoid inclusion of <algorithm>
    constexpr std::size_t min_size(std::size_t x, std::size_t y) noexcept {
        return x < y ? x : y;
    }
}

///////////////////// Comparisons

/// flat_equal_to<>
template <class T = void> struct flat_equal_to {
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::equal_impl<0, flat_tuple_size_v<T> >::cmp(x, y);
    }
};

template <> struct flat_equal_to<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::equal_impl<
            0,
            detail::min_size(flat_tuple_size_v<T>, flat_tuple_size_v<U>)
        >::cmp(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_not_equal<>
template <class T = void> struct flat_not_equal {
    bool operator()(const T& x, const T& y) const noexcept {
        return !flat_equal_to<T>{}(x, y);
    }
};

template <> struct flat_not_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return !flat_equal_to<void>{}(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_greater<>
template <class T = void> struct flat_greater {
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::less_impl<0, flat_tuple_size_v<T> >::cmp(y, x);
    }
};

template <> struct flat_greater<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::less_impl<
            0,
            detail::min_size(flat_tuple_size_v<T>, flat_tuple_size_v<U>)
        >::cmp(y, x);
    }

    typedef std::true_type is_transparent;
};

/// flat_less<>
template <class T = void> struct flat_less {
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::less_impl<0, flat_tuple_size_v<T> >::cmp(x, y);
    }
};

template <> struct flat_less<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::less_impl<
            0,
            detail::min_size(flat_tuple_size_v<T>, flat_tuple_size_v<U>)
        >::cmp(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_greater_equal<>
template <class T = void> struct flat_greater_equal {
    bool operator()(const T& x, const T& y) const noexcept {
        return !flat_less<T>{}(x, y);
    }
};

template <> struct flat_greater_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return !flat_less<>{}(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_less_equal<>
template <class T = void> struct flat_less_equal {
    bool operator()(const T& x, const T& y) const noexcept {
        return !flat_greater<T>{}(x, y);
    }
};

template <> struct flat_less_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return !flat_greater<>{}(x, y);
    }

    typedef std::true_type is_transparent;
};

/// flat_hash
template <class T> struct flat_hash {
    std::size_t operator()(const T& x) const noexcept {
        return detail::hash_impl<0, flat_tuple_size_v<T> >::compute(x);
    }
};




}} // namespace boost::pfr
