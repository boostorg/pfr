// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_UTILITY_HPP
#define BOOST_PFR_DETAIL_UTILITY_HPP

#include <boost/pfr/detail/config.hpp>
#include <cstddef>
#include <type_traits>

#if BOOST_PFR_USE_FALLBACK_FOR_BROKEN_STRUCTURED_BINDINGS == 0
#include <utility>
#endif

namespace boost { namespace pfr { namespace detail {

#if BOOST_PFR_USE_FALLBACK_FOR_BROKEN_STRUCTURED_BINDINGS == 0

using std::integer_sequence;
using std::index_sequence;
using std::forward;
using std::move;

#else // BOOST_PFR_USE_FALLBACK_FOR_BROKEN_STRUCTURED_BINDINGS == 1

template <class T, T... Ints>
struct integer_sequence
{
};

template<std::size_t... Ints>
using index_sequence = integer_sequence<std::size_t, Ints...>;

template<class T>
constexpr T&& forward(typename std::remove_reference<T>::type& lval) noexcept {
    return static_cast<T&&>(lval);
}

template<class T>
constexpr T&& forward(typename std::remove_reference<T>::type&& rval) noexcept {
    static_assert(!std::is_lvalue_reference<T>::value, "template argument substituting T is an lvalue reference type");
    return static_cast<T&&>(rval);
}

template<class T>
constexpr typename std::remove_reference<T>::type&& move(T&& val) noexcept {
    return static_cast<typename std::remove_reference<T>::type&&>(val);
}

#endif

}}} // namespace boost::pfr::detail


#endif // BOOST_PFR_DETAIL_UTILITY_HPP

