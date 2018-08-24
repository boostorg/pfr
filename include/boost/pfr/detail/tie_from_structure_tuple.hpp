// Copyright (c) 2018 Adam Butcher, Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_TIE_FROM_STRUCTURE_TUPLE_HPP
#define BOOST_PFR_DETAIL_TIE_FROM_STRUCTURE_TUPLE_HPP
#pragma once

namespace boost { namespace pfr { namespace detail {

/// \brief A `std::tuple` capable of de-structuring assignment used to support
/// a tie of multiple lvalue references to fields of an aggregate T.
///
/// \sa boost::pfr::tie_from_structure
///
template <typename... Elements>
struct tie_from_structure_tuple : std::tuple<Elements&...> {
    using base = std::tuple<Elements&...>;
    using base::tuple;
    template <typename T>
    constexpr tie_from_structure_tuple& operator= (T const& t) {
        base::operator=(
            make_stdtiedtuple_from_tietuple(
                tie_as_tuple(t),
                std::make_index_sequence<tuple_size_v<T>>()));
        return *this;
    }
};

}}} // boost::pfr::detail

#endif // BOOST_PFR_DETAIL_TIE_FROM_STRUCTURE_TUPLE_HPP
