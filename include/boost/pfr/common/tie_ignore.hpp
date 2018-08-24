// Copyright (c) 2018 Adam Butcher, Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_COMMON_TIE_IGNORE_HPP
#define BOOST_PFR_COMMON_TIE_IGNORE_HPP
#pragma once

namespace boost { namespace pfr {

/// \brief Resolve ambiguity with std::ignore when used with
/// boost::pfr::tie_from_structure and boost::pfr::flat_tie_from_structure.
///
/// \b Example:
/// \code
///     using namespace boost::pfr;
///     tie_from_structure(i, ignore) = f();
///     flat_tie_from_structure(i, ignore) = f();
/// \endcode
constexpr struct swallow_assign {
    template <typename T> void operator= (T&&) const {}
} ignore;

}} // boost::pfr

#endif // BOOST_PFR_COMMON_TIE_IGNORE_HPP
