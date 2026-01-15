// Copyright (c) 2025-2026 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_INDEX_OF_HPP
#define BOOST_PFR_INDEX_OF_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

#if !defined(BOOST_USE_MODULES) || defined(BOOST_PFR_INTERFACE_UNIT)

#include <boost/pfr/detail/for_each_field.hpp>


#if !defined(BOOST_PFR_INTERFACE_UNIT)
#include <type_traits>
#include <utility>      // metaprogramming stuff
#endif

/// \file boost/pfr/index_of.hpp
/// \copybrief boost::pfr::index_of

namespace boost { namespace pfr {

namespace detail {

template <typename M>
struct address_comparing_visitor {
    template <class T>
    constexpr void operator()(const T&, std::size_t) noexcept {}

    constexpr void operator()(const M& field, std::size_t idx) noexcept {
        const void* field_address = std::addressof(field);
        if (target_address == field_address) {
            result = idx;
        }
    }

    const void* const target_address;
    std::size_t result;
};

}

BOOST_PFR_BEGIN_MODULE_EXPORT

template <typename T, typename M>
constexpr std::size_t index_of(M T::*mem_ptr, const T& value) noexcept {
    if (mem_ptr == nullptr) {
        return ~static_cast<std::size_t>(0);
    }

    detail::address_comparing_visitor<M> visitor{
        std::addressof(value.*mem_ptr),
        ~static_cast<std::size_t>(0)
    };
    ::boost::pfr::detail::for_each_field(value, visitor);

    return visitor.result;
}

template <typename T, typename M>
constexpr std::size_t index_of(M T::*mem_ptr) noexcept {
    constexpr T value{};
    return ::boost::pfr::index_of(mem_ptr, value);
}

BOOST_PFR_END_MODULE_EXPORT

}} // namespace boost::pfr

#endif  // #if !defined(BOOST_USE_MODULES) || defined(BOOST_PFR_INTERFACE_UNIT)

#endif // BOOST_PFR_INDEX_OF_HPP
