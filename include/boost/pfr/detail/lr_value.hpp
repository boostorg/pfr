// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_LR_VALUE_HPP
#define BOOST_PFR_DETAIL_LR_VALUE_HPP
#pragma once

// This header provides aliases rvalue_t and lvalue_t.
//
// Usage: template <class T> void foo(lvalue_t<T> lvalue_possible_cv_qualified);
//
// Those are useful for
//  * better type safety - you can validate at compile time that only l/rvalue reference is passed into the function
//  * documentation and readability - lvalue_t<T> is much better than T&& or T&&+SFINAE

namespace boost { namespace pfr { namespace detail {

/// Binds to rvalues
template <class T> using rvalue_t = T&&;

/// Binds to const and non-const lvalues
template <class T> using lvalue_t = T&;

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CONFIG_HPP
