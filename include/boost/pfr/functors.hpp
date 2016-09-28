// Copyright (c) 2016 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_FUNCTORS_HPP
#define BOOST_PFR_FUNCTORS_HPP

#pragma once

#if __cplusplus < 201402L
#   error C++14 is required for this header.
#endif

#include <boost/pfr/core.hpp>

/// \file boost/pfr/functors.hpp
/// Contains functors that can work with PODs and are close to the Standard Library ones.
/// Each functor \flattening{flattens} the POD type and iterates over its fields.

namespace boost { namespace pfr {

namespace detail {
    template <std::size_t I, std::size_t N>
    struct equal_impl {
        template <class T, class U>
        constexpr static bool cmp(const T& v1, const U& v2) noexcept {
            return ::std::get<I>(v1) == ::std::get<I>(v2)
                && equal_impl<I + 1, N>::cmp(v1, v2);
        }
    };

    template <std::size_t N>
    struct equal_impl<N, N> {
        template <class T, class U>
        constexpr static bool cmp(const T&, const U&) noexcept {
            return T::size_v == U::size_v;
        }
    };

    template <std::size_t I, std::size_t N>
    struct not_equal_impl {
        template <class T, class U>
        constexpr static bool cmp(const T& v1, const U& v2) noexcept {
            return ::boost::pfr::detail::sequence_tuple::get<I>(v1) != ::boost::pfr::detail::sequence_tuple::get<I>(v2)
                || not_equal_impl<I + 1, N>::cmp(v1, v2);
        }
    };

    template <std::size_t N>
    struct not_equal_impl<N, N> {
        template <class T, class U>
        constexpr static bool cmp(const T&, const U&) noexcept {
            return T::size_v != U::size_v;
        }
    };

    template <std::size_t I, std::size_t N>
    struct less_impl {
        template <class T, class U>
        constexpr static bool cmp(const T& v1, const U& v2) noexcept {
            using ::boost::pfr::detail::sequence_tuple::get;
            return get<I>(v1) < get<I>(v2)
                || (get<I>(v1) == get<I>(v2) && less_impl<I + 1, N>::cmp(v1, v2));
        }
    };

    template <std::size_t N>
    struct less_impl<N, N> {
        template <class T, class U>
        constexpr static bool cmp(const T&, const U&) noexcept {
            return T::size_v < U::size_v;
        }
    };

    template <std::size_t I, std::size_t N>
    struct less_equal_impl {
        template <class T, class U>
        constexpr static bool cmp(const T& v1, const U& v2) noexcept {
            using ::boost::pfr::detail::sequence_tuple::get;
            return get<I>(v1) < get<I>(v2)
                || (get<I>(v1) == get<I>(v2) && less_equal_impl<I + 1, N>::cmp(v1, v2));
        }
    };

    template <std::size_t N>
    struct less_equal_impl<N, N> {
        template <class T, class U>
        constexpr static bool cmp(const T&, const U&) noexcept {
            return T::size_v <= U::size_v;
        }
    };

    template <std::size_t I, std::size_t N>
    struct greater_impl {
        template <class T, class U>
        constexpr static bool cmp(const T& v1, const U& v2) noexcept {
            using ::boost::pfr::detail::sequence_tuple::get;
            return get<I>(v1) > get<I>(v2)
                || (get<I>(v1) == get<I>(v2) && greater_impl<I + 1, N>::cmp(v1, v2));
        }
    };

    template <std::size_t N>
    struct greater_impl<N, N> {
        template <class T, class U>
        constexpr static bool cmp(const T&, const U&) noexcept {
            return std::tuple_size<T>::value > std::tuple_size<U>::value;
        }
    };

    template <std::size_t I, std::size_t N>
    struct greater_equal_impl {
        template <class T, class U>
        constexpr static bool cmp(const T& v1, const U& v2) noexcept {
            using ::boost::pfr::detail::sequence_tuple::get;
            return get<I>(v1) > get<I>(v2)
                || (get<I>(v1) == get<I>(v2) && greater_equal_impl<I + 1, N>::cmp(v1, v2));
        }
    };

    template <std::size_t N>
    struct greater_equal_impl<N, N> {
        template <class T, class U>
        constexpr static bool cmp(const T&, const U&) noexcept {
            return std::tuple_size<T>::value >= std::tuple_size<U>::value;
        }
    };

    template <typename SizeT>
    constexpr void hash_combine(SizeT& seed, SizeT value) noexcept {
        seed ^= value + 0x9e3779b9 + (seed<<6) + (seed>>2);
    }

    template <std::size_t I, std::size_t N>
    struct hash_impl {
        template <class T>
        constexpr static std::size_t compute(const T& val) noexcept {
            typedef typename boost::pfr::flat_tuple_element<I, T>::type elem_t;
            std::size_t h = std::hash<elem_t>()( ::std::get<I>(val) );
            hash_combine(h, hash_impl<I + 1, N>::compute(val) );
            return h;
        }
    };

    template <std::size_t N>
    struct hash_impl<N, N> {
        template <class T>
        constexpr static std::size_t compute(const T&) noexcept {
            return 0;
        }
    };

///////////////////// Define min_element and to avoid inclusion of <algorithm>
    constexpr std::size_t min_size(std::size_t x, std::size_t y) noexcept {
        return x < y ? x : y;
    }
} // namespace detail

///////////////////// Comparisons

/// \brief std::equal_to like flattening comparator
template <class T = void> struct flat_equal_to {
    /// \return \b true if each field of \b x equals the field with same index of \b y
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::tie_as_flat_tuple(x) == detail::tie_as_flat_tuple(y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const noexcept;
#endif
};

/// @cond
template <> struct flat_equal_to<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::tie_as_flat_tuple(x) == detail::tie_as_flat_tuple(y);
    }

};
/// @endcond

/// \brief std::not_equal like flattening comparator
template <class T = void> struct flat_not_equal {
    /// \return \b true if at least one field \b x not equals the field with same index of \b y
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::tie_as_flat_tuple(x) != detail::tie_as_flat_tuple(y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const noexcept;
#endif
};

/// @cond
template <> struct flat_not_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::tie_as_flat_tuple(x) != detail::tie_as_flat_tuple(y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::greater like flattening comparator
template <class T = void> struct flat_greater {
    /// \return \b true if field of \b x greater than the field with same index of \b y and all previous fields of \b x eqeal to the same fields of \b y
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::tie_as_flat_tuple(x) > detail::tie_as_flat_tuple(y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const noexcept;
#endif
};

/// @cond
template <> struct flat_greater<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::tie_as_flat_tuple(x) > detail::tie_as_flat_tuple(y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::less like flattening comparator
template <class T = void> struct flat_less {
    /// \return \b true if field of \b x less than the field with same index of \b y and all previous fields of \b x eqeal to the same fields of \b y
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::tie_as_flat_tuple(x) < detail::tie_as_flat_tuple(y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const noexcept;
#endif
};

/// @cond
template <> struct flat_less<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::tie_as_flat_tuple(x) < detail::tie_as_flat_tuple(y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::greater_equal like flattening comparator
template <class T = void> struct flat_greater_equal {
    /// \return \b true if field of \b x greater than the field with same index of \b y and all previous fields of \b x eqeal to the same fields of \b y;
    /// or if each field of \b x equals the field with same index of \b y .
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::tie_as_flat_tuple(x) >= detail::tie_as_flat_tuple(y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const noexcept;
#endif
};

/// @cond
template <> struct flat_greater_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::tie_as_flat_tuple(x) >= detail::tie_as_flat_tuple(y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/// \brief std::less_equal like flattening comparator
template <class T = void> struct flat_less_equal {
    /// \return \b true if field of \b x less than the field with same index of \b y and all previous fields of \b x eqeal to the same fields of \b y;
    /// or if each field of \b x equals the field with same index of \b y .
    bool operator()(const T& x, const T& y) const noexcept {
        return detail::tie_as_flat_tuple(x) <= detail::tie_as_flat_tuple(y);
    }

#ifdef BOOST_PFR_DOXYGEN_INVOKED
    /// This typedef exists only if T \b is void
    typedef std::true_type is_transparent;

    /// This operator allows comparison of \b x and \b y that have different type.
    /// \pre Exists only if T \b is void.
    template <class V, class U> bool operator()(const V& x, const U& y) const noexcept;
#endif
};

/// @cond
template <> struct flat_less_equal<void> {
    template <class T, class U>
    bool operator()(const T& x, const U& y) const noexcept {
        return detail::tie_as_flat_tuple(x) <= detail::tie_as_flat_tuple(y);
    }

    typedef std::true_type is_transparent;
};
/// @endcond

/*
/// \brief std::hash like flattening functor
template <class T> struct flat_hash {
    /// \return hash value of \b x
    std::size_t operator()(const T& x) const noexcept {
        return detail::hash_impl<0, flat_tuple_size_v<T> >::compute(detail::tie_as_flat_tuple(x));
    }
};
*/
}} // namespace boost::pfr

#endif // BOOST_PFR_FUNCTORS_HPP
