
// Copyright (c) 2023 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_STDARRAY_HPP
#define BOOST_PFR_DETAIL_STDARRAY_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <utility> // metaprogramming stuff
#include <tuple>

#include <boost/pfr/detail/sequence_tuple.hpp>

namespace boost { namespace pfr { namespace detail {

template <class T, std::size_t... I>
constexpr auto make_stdarray_from_tietuple(const T& t, std::index_sequence<I...>) noexcept {
    return std::array{
        boost::pfr::detail::sequence_tuple::get<I>(t)...
    };
}

}}}

#endif // BOOST_PFR_DETAIL_STDARRAY_HPP

