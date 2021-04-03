// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_INTEGER_SEQUENCE_HPP
#define BOOST_PFR_DETAIL_INTEGER_SEQUENCE_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#if BOOST_PFR_USE_STD_INTEGRAL_SEQUENCE == 1
#include <utility>
#endif

namespace boost { namespace pfr { namespace detail {

#if BOOST_PFR_USE_STD_INTEGRAL_SEQUENCE == 0

template <typename T, T... Ints>
struct integer_sequence
{
};

#else // BOOST_PFR_USE_STD_INTEGRAL_SEQUENCE == 1

template <typename T, T... Ints>
using integer_sequence = std::integer_sequence<T, Ints...>;

#endif // BOOST_PFR_USE_STD_INTEGRAL_SEQUENCE == 1

template<std::size_t... Ints>
using index_sequence = integer_sequence<std::size_t, Ints...>;

}}} // namespace boost::pfr::detail

#endif

