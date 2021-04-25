// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_MEMPTR_CAST_HPP
#define BOOST_PFR_DETAIL_MEMPTR_CAST_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>

namespace boost { namespace pfr { namespace detail {

    template<typename T>
    /*constexpr*/ inline T memptr_cast(std::size_t offset) noexcept
    {
        // TODO: implement offset checking
        // TODO: implement check that T is correct member pointer
        static_assert(sizeof(T) == sizeof(std::size_t), "====================> Boost.PFR: Internal error while casting offset to member pointer");
        union {
            T memptr;
            std::size_t offset_;
        };
        offset_ = offset;
        return memptr;
    }

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_MEMPTR_CAST_HPP
