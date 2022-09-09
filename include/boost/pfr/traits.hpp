// Copyright (c) 2022 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_TRAITS_HPP
#define BOOST_PFR_TRAITS_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/detail/traits_fwd.hpp>

/// \file boost/pfr/traits.hpp
/// Contains trait \forcedlink{is_reflectable} for detecting an ability to reflect type. Also contain traits(like \forcedlink{is_view}) to extract additional information about reflectable or non-reflectable types.
///
/// \b Synopsis:

namespace boost { namespace pfr {

// Special tag
struct all_default_tag;



/// Has a static const member variable `value` that equals true when it known that type T can be reflected using Boost.PFR.
///
/// \b Example:
/// \code
///     template<class T, std::enable_if_t<boost::pfr::is_reflectable<T, boost::pfr::boost_json_tag>::value>* = nullptr>
///     T tag_invoke(boost::json::value_to_tag<T>, const boost::json::value& jv); // overload for definitely reflectable type(view or non-view)
/// \endcode
/// \note The behavior of a program that adds specializations for is_reflectable is undefined.
///
/// \podinteraction if you want to know how to make a user-defined type reflectable.
///
/// \customadaptor using is_reflectable trait and so others.
template<class T, class WhatFor = all_default_tag>
struct is_reflectable; // TODO: Impl

/// Has a static const member variable `value` that equals true when type T is a View manipulator.
///
/// \b Example:
/// \code
///     template<class T, std::enable_if_t<!boost::pfr::is_reflectable<T, boost::pfr::boost_json_tag>::value && boost::pfr::is_view<T>::value>* = nullptr>
///     T tag_invoke(boost::json::value_to_tag<T>, const boost::json::value& jv);  // overload for non-reflectable view
/// \endcode
/// \note The behavior of a program that adds specializations for is_view is undefined.
///
/// \podview if you want to know more details about View manipulator.
///
/// \customadaptor using is_view trait and so others.
template<class T>
struct is_view; // TODO: Impl



/// `is_reflectable_v` is a template variable that equals true when it known that type T can be reflected using Boost.PFR.
///
/// \b Example:
/// \code
///     template<class T, std::enable_if_t<boost::pfr::is_reflectable_v<T, boost::pfr::boost_json_tag>>* = nullptr>
///     T tag_invoke(boost::json::value_to_tag<T>, const boost::json::value& jv); // overload for definitely reflectable type(view or non-view)
/// \endcode
///
/// \podinteraction if you want to know how to make a user-defined type reflectable.
///
/// \customadaptor using is_reflectable_v template variable and so others.
template<class T, class WhatFor = all_default_tag>
constexpr bool is_reflectable_v = is_reflectable<T, WhatFor>::value;

/// `is_view_v` is a template variable that equals true when type T is a View manipulator.
///
/// \b Example:
/// \code
///     template<class T, std::enable_if_t<!boost::pfr::is_reflectable_v<T, boost::pfr::boost_json_tag> && boost::pfr::is_view_v<T>>* = nullptr>
///     T tag_invoke(boost::json::value_to_tag<T>, const boost::json::value& jv);  // overload for non-reflectable view
/// \endcode
///
/// \podview if you want to know more details about View manipulator.
///
/// \customadaptor using is_view_v template variable and so others.
template<class T>
constexpr bool is_view_v = is_view<T>::value;

}} // namespace boost::pfr

#endif // BOOST_PFR_TRAITS_HPP

