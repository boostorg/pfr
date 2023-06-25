// Copyright (c) 2023 Bela Schaum, X-Ryl669, Denis Mikhailov.
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


// Initial implementation by Bela Schaum, https://github.com/schaumb
// The way to make it union and UB free by X-Ryl669, https://github.com/X-Ryl669
//

#ifndef BOOST_PFR_CORE_NAME_HPP
#define BOOST_PFR_CORE_NAME_HPP 
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/detail/core_name.hpp>

#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/stdarray.hpp>
#include <boost/pfr/detail/make_integer_sequence.hpp>

#include <cstddef>
#include <string_view>

#include <boost/pfr/tuple_size.hpp>

namespace boost { namespace pfr {

template <std::size_t I, class T>
constexpr std::string_view get_name() noexcept {
    static_assert(sizeof(T) && BOOST_PFR_ENABLE_GETTING_NAMES, "====================> Boost.PFR: Calling boost::pfr::get_name is allowed only in C++20");
    return detail::sequence_tuple::get<I>( detail::tie_as_names_tuple<T>() );
}

// FIXME: implement this
// template<class U, class T>
// constexpr std::string_view get_name() noexcept {
//     static_assert(sizeof(T) && BOOST_PFR_ENABLE_GETTING_NAMES, "====================> Boost.PFR: Calling boost::pfr::get_name is allowed only in C++20");
//     return detail::sequence_tuple::get_by_type_impl<U>( detail::tie_as_names_tuple<T>() );
// }

template <class T>
constexpr auto names_as_array() noexcept {
    static_assert(sizeof(T) && BOOST_PFR_ENABLE_GETTING_NAMES, "====================> Boost.PFR: Calling boost::pfr::names_as_array is allowed only in C++20");
    return detail::make_stdarray_from_tietuple(
	detail::tie_as_names_tuple<T>(),
	detail::make_index_sequence< tuple_size_v<T> >()
    );
}


}}

#endif // BOOST_PFR_CORE_NAME_HPP 

