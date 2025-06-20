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
  CustomFields2 cf2;
  boost::pfr::for_each_field_with_name(cf2, [](const auto&, const auto&) {});
}
