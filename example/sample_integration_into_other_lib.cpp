// Copyright 2022 Denis Mikhailov

// Distributed under the Boost Software License, Version 1.0.
// (See the accompanying file LICENSE_1_0.txt
// or a copy at <http://www.boost.org/LICENSE_1_0.txt>.)

//[pfr_sample_adapting
/*`
    The following example shows how to adapt Boost.PFR into another library that can works with tuple-like interface(like Boost.JSON):
*/
#include <boost/json.hpp>
#include <boost/pfr/traits.hpp>
#include <boost/pfr/tuple_size.hpp>
#include <boost/pfr/core.hpp>
#include <boost/pfr/view.hpp>

/// Usage:
///     struct some_person {std::string name; unsigned birth_year;};
///     ...
///     boost::json::value raw{"Edgar Allan Poe", 1809};
///     some_person val = boost::json::value_to<
///         boost::pfr::view_t<some_person>
///       >(raw);
///     std::cout << boost::pfr::io(val);
///
/// Output: {"Edgar Allan Poe", 1809}

template< class T >
using remove_cvref_t = std::remove_cv_t<std::remove_reference_t<T>>;

// 1. Extend Boost.PFR, registrate new tags, and implement is_reflectable's behaviour for these tags.
//    In this sample we registrated two tags - for boost::json::value_from and for boost::json::value_to.
namespace boost::pfr {
  struct boost_json_value_from_tag;
  struct boost_json_value_to_tag;

  namespace extension
  {
    template<class Tag>
    struct is_reflectable_impl;

    template<template<class> class CondNotForView>
    struct is_reflectable_impl_base {
      template<class T>
      struct apply
      {
        constexpr static auto call() noexcept {
            if constexpr (!boost::pfr::is_view<T>::value) {
                return boost::pfr::is_reflectable<T>{};
            } else {
                using value_type = remove_cvref_t<
                  decltype(std::declval<T>().value)>;
                return std::integral_constant<bool,
                    !CondNotForView<value_type>::value
                  >{};
            }
        }
        using type = decltype(call());
        static constexpr bool value = type::value;
      };
    };

    template<>
    struct is_reflectable_impl<boost_json_value_from_tag>
        : is_reflectable_impl_base<boost::json::has_value_from>
    {
    };

    template<>
    struct is_reflectable_impl<boost_json_value_to_tag>
        : is_reflectable_impl_base<boost::json::has_value_to>
    {
    };
  } // namespace extension
} // namespace boost::pfr

// just helpers, never mind..
namespace my_ext::detail {
  template<class T>
  using is_reflectable_to = boost::pfr::is_reflectable<std::remove_reference_t<T>,
                                      boost::pfr::boost_json_value_to_tag>;

  template<class T>
  using is_reflectable_from = boost::pfr::is_reflectable<std::remove_reference_t<T>,
                                      boost::pfr::boost_json_value_from_tag>;

  template<class T>
  using is_nonreflectable_view_to = std::integral_constant<bool, (
                                      (!is_reflectable_to<std::remove_reference_t<T>>::value) &&
                                      boost::pfr::is_view<std::remove_reference_t<T>>::value)>;

  template<class T>
  using is_nonreflectable_view_from = std::integral_constant<bool, (
                                      (!is_reflectable_from<std::remove_reference_t<T>>::value) &&
                                      boost::pfr::is_view<std::remove_reference_t<T>>::value)>;
} // namespace my_ext::detail

// 2. Extend the library using the features it provides to be extendable and use is_reflectable trait with our new tags.
//    Doing this step you should provide for View manipulator possibility to respect reflection from library that you extend.
//    In this sample we created yet another tag_invoke overload for this.
namespace boost::json {
  template<class T, std::enable_if_t<my_ext::detail::is_reflectable_to<T>::value>* = nullptr>
  T tag_invoke(boost::json::value_to_tag<T>, const boost::json::value& jv)
  {
    auto v = T{};
    const auto& arr = jv.as_array();
    if (boost::pfr::tuple_size<std::remove_reference_t<T>>() != arr.size()) {
      throw std::invalid_argument("array size does not match tuple size");
    }
    boost::pfr::for_each_field(v, [&arr](auto& value, const auto i){
        constexpr auto I = std::decay_t<decltype(i)>::value;
        using element_type = boost::pfr::tuple_element_t<I, std::remove_reference_t<T>>;
        value = boost::json::value_to<element_type>(arr[i]);
    });
    return v;
  }

  template<class T, std::enable_if_t<my_ext::detail::is_nonreflectable_view_to<T>::value>* = nullptr>
  T tag_invoke(boost::json::value_to_tag<T>, const boost::json::value& jv)
  {
    using value_type = remove_cvref_t<decltype(std::declval<T>().value)>;
    return boost::pfr::view(boost::json::value_to<value_type>(jv));
  }

  template<class T, std::enable_if_t<my_ext::detail::is_reflectable_from<T>::value>* = nullptr>
  void tag_invoke(boost::json::value_from_tag, boost::json::value& jv, T&& from)
  {
    auto& arr = jv.emplace_array();
    arr.reserve(boost::pfr::tuple_size<std::remove_reference_t<T>>());
    boost::pfr::for_each_field(std::forward<T>(from), [&arr](auto&& val) {
      arr.emplace_back(boost::json::value_from(
        std::forward<decltype(val)>(val),
        arr.storage()));
    });
  }

  template<class T, std::enable_if_t<my_ext::detail::is_nonreflectable_view_from<T>::value>* = nullptr>
  void tag_invoke(boost::json::value_from_tag, boost::json::value& jv, T&& v)
  {
    if constexpr (std::is_rvalue_reference<T&&>::value) {
        jv = boost::json::value_from(std::forward<decltype(v.value)>(v.value));
    } else {
        jv = boost::json::value_from(v.value);
    }
  }
} // namespace boost::json
//] [/pfr_sample_adapting]


#include <iostream>
#include "boost/pfr/io.hpp"

namespace json = boost::json;

struct some_person {
  std::string name;
  unsigned birth_year;
};

int main() {
  json::value raw{"Edgar Allan Poe", 1809};
  some_person val = json::value_to<boost::pfr::view_t<some_person>>(raw);

  std::cout << boost::pfr::io(val);         // Outputs: {"Edgar Allan Poe", 1809}
} 

