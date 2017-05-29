// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifndef BOOST_PFR_DETAIL_CORE17_HPP
#define BOOST_PFR_DETAIL_CORE17_HPP

// TODO: rename as_tuple to tie_as_tuple
#include <boost/pfr/detail/core17_generated.hpp>

#include <boost/pfr/detail/for_each_field_impl.hpp>

namespace boost { namespace pfr { namespace detail {

template <class T, class F, std::size_t... I>
void for_each_field_dispatcher(T&& t, F&& f, std::index_sequence<I...>) {
    std::forward<F>(f)(
        detail::as_tuple(std::forward<T>(t))
    );
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE17_HPP
