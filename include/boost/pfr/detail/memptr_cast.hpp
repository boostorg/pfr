// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_MEMPTR_CAST_HPP
#define BOOST_PFR_DETAIL_MEMPTR_CAST_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>
#include <cstdint>
#include <limits>

namespace boost { namespace pfr { namespace detail {

    constexpr std::uint8_t  unsigned_by_size(size_t_<1>) noexcept { return 0; }
    constexpr std::uint16_t unsigned_by_size(size_t_<2>) noexcept { return 0; }
    constexpr std::uint32_t unsigned_by_size(size_t_<4>) noexcept { return 0; }
    constexpr std::uint64_t unsigned_by_size(size_t_<8>) noexcept { return 0; }

    template<typename T, std::size_t I>
    inline T memptr_cast(size_t_<I> offset)
    {
        using raw_type = decltype(unsigned_by_size(size_t_<sizeof(T)>{ }));

        static_assert(
            sizeof(raw_type) <= sizeof(std::size_t), 
            "====================> Boost.PFR: Internal error while casting offset to member pointer."
        );
        static_assert(
            decltype(offset)::value <= (std::size_t)(std::numeric_limits<raw_type>::max)(), 
            "====================> Boost.PFR: Internal error while casting offset to member pointer: overflow was detected"
        );

        union {
            T memptr;
            raw_type offset_;
        };
        offset_ = static_cast<raw_type>(offset);
        return memptr;
    }

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_MEMPTR_CAST_HPP
