// Copyright (c) 2021-2023 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_CORE_MEMPTR_HPP
#define BOOST_PFR_CORE_MEMPTR_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#include <boost/pfr/detail/core_memptr.hpp>

#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/stdtuple.hpp>

#include <type_traits>
#include <utility>      // metaprogramming stuff

#include <boost/pfr/core.hpp>
#include <boost/pfr/type_identity.hpp>

/// \file boost/pfr/core_memptr.hpp
/// Contains all the basic interfaces for working with member pointers of some structure  \forcedlink{get_memptr}, and others.
///
/// \b Synopsis:

namespace boost { namespace pfr {

/// \brief Returns member pointer to a field with index `I` in some \aggregate with type 'T'.
///
/// \b Example:
/// \code
///     struct my_struct { int i, short s; };
///     my_struct s {10, 11};
///     assert(boost::pfr::get_memptr<0>(s) == &my_struct::i);
///     auto memptr = boost::pfr::get_memptr<1>(s);
///     s.*memptr = 0;
/// \endcode
template<std::size_t I, class T>
inline auto get_memptr(boost::pfr::type_identity<T>) noexcept
{
    return detail::sequence_tuple::get<I>( detail::tie_as_memptrs_tuple<T>() );
}

/// \overload get_memptr
template<std::size_t I, class T>
inline auto get_memptr(const T&) noexcept
{
    // TODO: test it without default constructor
    return get_memptr<I>(boost::pfr::type_identity<T>{});
}

}} // namespace boost::pfr

#endif // BOOST_PFR_CORE_MEMPTR_HPP
