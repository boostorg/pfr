// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_POSSIBLE_REFLECTABLE_HPP
#define BOOST_PFR_DETAIL_POSSIBLE_REFLECTABLE_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>
#include <boost/pfr/traits_fwd.hpp>

#if !defined(BOOST_PFR_INTERFACE_UNIT)
#include <array>       // for std::array
#include <cstddef>     // for std::size_t
#include <type_traits> // for std::is_aggregate
#endif

namespace boost { namespace pfr { namespace detail {

// std::array<T, N> is an aggregate, but it stores its elements in a C array
// data member. Boost.PFR can not reflect types with C array members yet (see
// https://github.com/boostorg/pfr/issues/20), so std::array must not be
// treated as implicitly reflectable.
template <class T>
struct is_stdarray : std::false_type {};

template <class T, std::size_t N>
struct is_stdarray<std::array<T, N>> : std::true_type {};

///////////////////// Returns false when the type exactly wasn't be reflectable
template <class T, class WhatFor>
constexpr decltype(is_reflectable<T, WhatFor>::value) possible_reflectable(long) noexcept {
    return is_reflectable<T, WhatFor>::value;
}

#if BOOST_PFR_ENABLE_IMPLICIT_REFLECTION

template <class T, class WhatFor>
constexpr bool possible_reflectable(int) noexcept {
    using type = std::remove_cv_t<T>;
#   if  defined(__cpp_lib_is_aggregate)
    return std::is_aggregate<type>() && !detail::is_stdarray<type>::value;
#   else
    return !detail::is_stdarray<type>::value;
#   endif
}

#else

template <class T, class WhatFor>
constexpr bool possible_reflectable(int) noexcept {
    // negative answer here won't change behaviour in PFR-dependent libraries(like Fusion)
    return false;
}

#endif

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_POSSIBLE_REFLECTABLE_HPP


