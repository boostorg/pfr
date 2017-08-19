// Copyright (c) 2016-2017 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifndef BOOST_PFR_DETAIL_CORE17_HPP
#define BOOST_PFR_DETAIL_CORE17_HPP

#include <boost/pfr/detail/core17_generated.hpp>
#include <boost/pfr/detail/for_each_field_impl.hpp>

namespace boost { namespace pfr { namespace detail {

struct do_not_define_std_tuple_size_for_me {
    bool test1 = true;
};

template <class T>
constexpr bool do_structured_bindings_work() noexcept { // ******************************************* IN CASE OF ERROR READ THE FOLLOWING LINES IN boost/pfr/detail/core17.hpp FILE:
    const auto& [a] = T{}; // ******************************************* IN CASE OF ERROR READ THE FOLLOWING LINES IN boost/pfr/detail/core17.hpp FILE:

    /****************************************************************************
    *
    * It looks like your compiler or Standard Library can not handle C++17
    * structured bindings.
    *
    * Workaround: Define BOOST_PFR_USE_CPP17 to 0
    * It will disable the C++17 features for Boost.PFR library.
    *
    * Sorry for the inconvenience caused.
    *
    ****************************************************************************/

    return a;
}

static_assert(
    do_structured_bindings_work<do_not_define_std_tuple_size_for_me>(),
    "Your compiler can not handle C++17 structured bindings. Read the above comments for workarounds."
);


template <class T, class F, std::size_t... I>
void for_each_field_dispatcher(T&& t, F&& f, std::index_sequence<I...>) {
    std::forward<F>(f)(
        detail::as_tuple(std::forward<T>(t))
    );
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE17_HPP
