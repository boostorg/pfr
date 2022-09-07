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
/// TODO: desc
///
/// \b Synopsis:

namespace boost { namespace pfr {

// Special tag
struct for_everywhat_tag; // TODO: rename

template<class T, class WhatFor=for_everywhat_tag>
struct is_reflectable; // TODO: Impl

template<class T>
struct is_view; // TODO: Impl

template<typename T>
struct is_reference; // TODO: Impl

// TODO: add aliases for all traits

}} // namespace boost::pfr

#endif // BOOST_PFR_TRAITS_HPP

