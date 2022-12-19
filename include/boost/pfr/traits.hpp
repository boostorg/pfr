// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_TRAITS_HPP
#define BOOST_PFR_TRAITS_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/detail/possible_reflectable.hpp>
#include <type_traits>

/// \file boost/pfr/traits.hpp
/// Contains traits \forcedlink{is_reflectable} and \forcedlink{is_implicitly_reflectable} for detecting an ability to reflect type.
///
/// \b Synopsis:

namespace boost { namespace pfr {

/// Has a static const member variable `value` when it known that type T can or can't be reflected using Boost.PFR; otherwise, there is no member variable.
/// Every user may(and in some difficult cases - should) specialize is_reflectable on his own.
///
/// \b Example:
/// \code
///     namespace boost { namespace pfr {
///         template<class All> struct is_reflectable<A, All> : std::false_type {};       // 'A' won't be interpreted as reflectable everywhere
///         template<> struct is_reflectable<B, boost_fusion_tag> : std::false_type {};   // 'B' won't be interpreted as reflectable in only Boost Fusion
///     }}
/// \endcode
/// \note is_reflectable affects is_implicitly_reflectable, the decision made by is_reflectable has more priority than is_implicitly_reflectable,
///       because is_reflectable is more sharp than is_implicitly_reflectable
///
template<class T, class WhatFor>
struct is_reflectable { /*  do not has 'value' because value is unknown */ };

// these specs can't be inherited from 'std::integral_constant< bool, boost::pfr::is_reflectable<T, WhatFor>::value >',
// because it will break the sfinae-friendliness
template<class T, class WhatFor>
struct is_reflectable<const T, WhatFor> : boost::pfr::is_reflectable<T, WhatFor> {};

template<class T, class WhatFor>
struct is_reflectable<volatile T, WhatFor> : boost::pfr::is_reflectable<T, WhatFor> {};

template<class T, class WhatFor>
struct is_reflectable<const volatile T, WhatFor> : boost::pfr::is_reflectable<T, WhatFor> {};

#if BOOST_PFR_ENABLE_IMPLICIT_REFLECTION
/// Checks the input type for the potential to be reflected.
/// Specialize is_reflectable if you are disagree with is_implicitly_reflectable's default decision.
template<class T, class WhatFor>
using is_implicitly_reflectable = std::integral_constant< bool, boost::pfr::detail::possible_reflectable<T, WhatFor>(1L) >;
#endif

/// Checks the input type for having of reference semantic.
/// Returns true if T can be passed by value as cheap as any reference.
/// \note The behavior of a program that adds specializations for is_view is undefined.
///
template<class T>
struct is_view : std::integral_constant<bool, false> {};

#if BOOST_PFR_ENABLE_IMPLICIT_REFLECTION
/// Checks the input type for the potential to be reflected.
/// Specialize is_reflectable if you are disagree with is_implicitly_reflectable_v's default decision.
template<class T, class WhatFor>
constexpr bool is_implicitly_reflectable_v = is_implicitly_reflectable<T, WhatFor>::value;
#endif

/// Checks the input type for having of reference semantic.
/// Equals true for T that can be passed by value as cheap as any reference.
template<class T>
constexpr bool is_view_v = is_view<T>::value;

}} // namespace boost::pfr

#endif // BOOST_PFR_TRAITS_HPP

