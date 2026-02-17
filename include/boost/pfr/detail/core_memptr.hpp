// Copyright (c) 2021-2023 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_CORE_MEMPTR_HPP
#define BOOST_PFR_DETAIL_CORE_MEMPTR_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>
#include <boost/pfr/detail/core.hpp>
#include <boost/pfr/detail/fields_count.hpp>
#include <boost/pfr/detail/sequence_tuple.hpp>
#include <boost/pfr/detail/make_integer_sequence.hpp>
#include <boost/pfr/detail/align.hpp>
#include <boost/pfr/detail/memptr_cast.hpp>

// Each core_memptr provides `boost::pfr::detail::tie_as_memptrs_tuple` and
// `boost::pfr::detail::for_each_memptr_dispatcher` functions.
//
// The whole memptr's functionality in PFR library is build on top of those two functions.

namespace boost { namespace pfr { namespace detail {

template <class... Args>
constexpr auto make_sequence_tuple(Args... args) noexcept {
    return sequence_tuple::tuple<Args...>{ args... };
}

template <std::size_t I, class T>
using tuple_element_ = sequence_tuple::tuple_element<I, decltype( detail::tie_as_tuple(std::declval<T&>()) ) >;

template <std::size_t I, class T>
using tuple_memptr_t = typename detail::tuple_element_<I, T>::type T::*;


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T, class I>
constexpr std::size_t tie_as_offsets_tuple_impl_apply(I i, std::size_t& offset, std::size_t& space) noexcept
{
    using element_type = typename detail::tuple_element_<decltype(i)::value, T>::type;
    std::size_t aligned = detail::align_offset(alignof(element_type), sizeof(element_type), offset, space);
    offset += sizeof(element_type);
    space -= sizeof(element_type);
    return aligned;
}

template<class T, std::size_t... I>
constexpr auto tie_as_offsets_tuple_impl(std::index_sequence<I...>, std::size_t& offset, std::size_t& space) noexcept
{
    return detail::make_sequence_tuple( tie_as_offsets_tuple_impl_apply<T>(size_t_<I>{}, offset, space)... );
}

template<class T>
constexpr auto tie_as_offsets_tuple_impl(std::index_sequence<>, std::size_t& offset, std::size_t& space) noexcept
{
    // TODO: test for empty structure
    (void)offset;
    (void)space;
    return detail::make_sequence_tuple();
}

template<class T>
constexpr auto tie_as_offsets_tuple() noexcept
{
    // TODO: discard structures with non-standard alignment and bit fields
    std::size_t offset = 0;
    std::size_t space = sizeof(T);

    return tie_as_offsets_tuple_impl<T>(detail::make_index_sequence<detail::fields_count<T>()>{}, offset, space);
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

template<class T, std::size_t... I>
inline auto tie_as_memptrs_tuple_impl(std::index_sequence<I...>) noexcept
{
    constexpr auto offsets = tie_as_offsets_tuple<T>();
    return detail::make_sequence_tuple( detail::memptr_cast<detail::tuple_memptr_t<I, T>>(size_t_<sequence_tuple::get<I>(offsets)>{})... );
}

template <class T>
inline auto tie_as_memptrs_tuple() noexcept {
    static_assert(
        !std::is_union<T>::value,
        "====================> Boost.PFR: For safety reasons it is forbidden to reflect unions. See `Reflection of unions` section in the docs for more info."
    );

    return tie_as_memptrs_tuple_impl<T>(detail::make_index_sequence<detail::fields_count<T>()>{});
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE_MEMPTR_HPP
