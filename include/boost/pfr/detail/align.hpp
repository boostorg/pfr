// Copyright (c) 2021 Denis Mikhailov
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_ALIGN_HPP
#define BOOST_PFR_DETAIL_ALIGN_HPP
#pragma once

#include <boost/pfr/detail/config.hpp>
#include <cstddef> // for std::size_t

namespace boost { namespace pfr { namespace detail {

    constexpr std::size_t align_offset(std::size_t alignment, std::size_t size, std::size_t& offset, std::size_t& space) noexcept
    {
        //BOOST_ASSERT(boost::alignment::detail::is_alignment(alignment)); TODO enable
        if (size <= space) {
            std::size_t p = ~(alignment - 1) & (offset + alignment - 1);
            std::size_t n = p - offset;
            if (n <= space - size) {
                offset = p;
                space -= n;
                return p;
            }
        }
        return (size_t)-1;
    }

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_ALIGN_HPP
