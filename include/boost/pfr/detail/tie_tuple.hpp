// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#ifndef BOOST_PFR_DETAIL_TIE_TUPLE_HPP
#define BOOST_PFR_DETAIL_TIE_TUPLE_HPP
#pragma once

#include <tuple>

namespace boost::pfr {
    template <typename T> constexpr auto structure_to_tuple(const T& val) noexcept;
}

namespace boost::pfr::detail {

/// \brief A `std::tuple` capable of de-structuring assignment used to support
/// a tie of multiple lvalue references to fields of an aggregate T.
///
/// \sa boost::pfr::tie
///
template <typename... Elements>
struct tie_tuple : std::tuple<Elements&...> {
    using base = std::tuple<Elements&...>;
    using base::tuple;
    using base::operator=;
    template <typename T>
    constexpr tie_tuple& operator= (T&& t) {
        base::operator=(boost::pfr::structure_to_tuple(std::forward<T>(t)));
        return *this;
    }
};

} // boost::pfr::detail

#endif // BOOST_PFR_DETAIL_TIE_TUPLE_HPP
