// Copyright (c) 2016-2021 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)


#ifndef BOOST_PFR_DETAIL_CORE17_HPP
#define BOOST_PFR_DETAIL_CORE17_HPP

#include <boost/pfr/detail/core17_generated.hpp>
#include <boost/pfr/detail/fields_count.hpp>
#include <boost/pfr/detail/for_each_field_impl.hpp>
#include <boost/pfr/detail/rvalue_t.hpp>

namespace boost { namespace pfr { namespace detail {

struct GuaranteedSimpleAggregate {
    bool test1 = true;
};

template <class T>
constexpr auto tie_as_tuple(T& val) noexcept { // ******************************************* IN CASE OF ERROR READ THE FOLLOWING LINES IN boost/pfr/detail/core17.hpp FILE:
  static_assert(
    !std::is_union<T>::value,
    "====================> Boost.PFR: For safety reasons it is forbidden to reflect unions. See `Reflection of unions` section in the docs for more info."
  );

  GuaranteedSimpleAggregate test{true};
  const auto& [a] = test; // ====================> Boost.PFR: Your compiler can not handle C++17 structured bindings. Read the below comments for workarounds.
  (void)a;

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

  typedef size_t_<boost::pfr::detail::fields_count<T>()> fields_count_tag;
  return boost::pfr::detail::tie_as_tuple(val, fields_count_tag{});
}

template <class T, class F, std::size_t... I>
void for_each_field_dispatcher(T& t, F&& f, std::index_sequence<I...>) {
    static_assert(
        !std::is_union<T>::value,
        "====================> Boost.PFR: For safety reasons it is forbidden to reflect unions. See `Reflection of unions` section in the docs for more info."
    );
    std::forward<F>(f)(
        detail::tie_as_tuple(t)
    );
}

}}} // namespace boost::pfr::detail

#endif // BOOST_PFR_DETAIL_CORE17_HPP
