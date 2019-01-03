// Copyright (c) 2018-2019 Antony Polukhin
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

// Test case for https://github.com/apolukhin/magic_get/issues/30

#include <memory>
#include <boost/pfr.hpp>
#include <boost/core/lightweight_test.hpp>

struct Message {
  std::unique_ptr<int> data;
};

int main() {
  Message message;
  auto& ptr = boost::pfr::get<0>(message);
  BOOST_TEST(ptr == nullptr);
  return boost::report_errors();
}
