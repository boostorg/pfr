// Copyright (c) 2018-2025 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Test case for https://github.com/boostorg/pfr/issues/30

#include <memory>
#include <boost/pfr.hpp>
#include <boost/core/lightweight_test.hpp>

// Some _MSC_VER are broken:
// boost/pfr/detail/fields_count.hpp(469): error C2338: static_assert failed:
// '====================> Boost.PFR: If there's no other failed static
// asserts then something went wrong. Please report this issue to the github
// along with the structure you're reflecting.'
//
// No known workaround
#if !defined(_MSC_VER) || _MSC_VER != 1944 || !(BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE)

struct Message {
  std::unique_ptr<int> data;
};

struct Message2 {
  std::unique_ptr<int> data41 = std::make_unique<int>(41);
  std::unique_ptr<int> data42 = std::make_unique<int>(42);
};

// Example from duplicate issue #45
struct UniquePtr {
    std::unique_ptr<int> a;
};
static_assert (boost::pfr::tuple_size_v<UniquePtr> == 1, "");

int main() {
  Message message;
  auto& ptr = boost::pfr::get<0>(message);
  BOOST_TEST(ptr == nullptr);

  Message2 message2;
  auto& ptr2 = boost::pfr::get<1>(message2);
  BOOST_TEST_EQ(*ptr2, 42);

  return boost::report_errors();
}

#else
int main() {
  return boost::report_errors();
}
#endif
