// Copyright (c) 2025-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <boost/pfr.hpp>

// Test inspired by https://github.com/boostorg/pfr/issues/208

#include <atomic>
#include <memory>
#include <string>
#include <string>
#include <type_traits>
#include <utility>
#include <vector>

template <typename T>
struct Field {
  Field() = default;

  template<typename Arg, class = decltype(T{std::declval<Arg&&>()})>
  constexpr Field(Arg&& arg) : value_{std::forward<Arg>(arg)} {}

 private:
  [[no_unique_address]] T value_;
};

struct CustomFields2 {
  Field<int> some_int;
  Field<std::vector<int>> some_vector;
  Field<std::unique_ptr<int>> some_unique_ptr;
  Field<std::shared_ptr<int>> some_shared_ptr;
  Field<std::atomic<int>> some_atomic;
};

int main() {

// Compilers have issues with this test in C++17.
//
// GCC-9 and GCC-10 are fine
//
// GCC-11:
// ./boost/pfr/detail/fields_count.hpp:351:58:   in constexpr expansion of boost::pfr::detail::fields_count_binary_search<CustomFields2, 0, 5>((boost::pfr::detail::is_one_element_range<0, 5>{}, boost::pfr::detail::is_one_element_range<0, 5>()), 1)
// libs/pfr/test/core_name/run/unique_ptr_wrapper.cpp:23:32: error: use of deleted function std::atomic<int>::atomic(const std::atomic<int>&)
//    23 |   constexpr Field(Arg&& arg) : value_{std::forward<Arg>(arg)} {}
//       |                                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// GCC-12:
// libs/pfr/test/core_name/run/unique_ptr_wrapper.cpp:39:39:   required from here
// libs/pfr/test/core_name/run/unique_ptr_wrapper.cpp:23:32: error: use of deleted function std::unique_ptr<_Tp, _Dp>::unique_ptr(const std::unique_ptr<_Tp, _Dp>&) [with _Tp = int]
//    23 |   constexpr Field(Arg&& arg) : value_{std::forward<Arg>(arg)} {}
//       |                                ^~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
//
// GCC-14 is fine
//
// Because of the above issues we test mostly in C++26.

#if BOOST_PFR_USE_CPP26 || (defined(__GNUC__) && (__GNUC__ != 11 && __GNUC__ != 12)) || defined(__clang__)
  CustomFields2 cf2;
  boost::pfr::for_each_field_with_name(cf2, [](const auto&, const auto&) {});
#endif
}
