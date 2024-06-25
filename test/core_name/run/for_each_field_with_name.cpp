// Copyright (c) 2016-2024 Lena Bertho
//
// Distributed under the Boost Software License, Version 1.0. (See accompanying
// file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

#include <map>
#include <string>

#include <boost/pfr/core_name.hpp>
#include <boost/core/lightweight_test.hpp>


struct SimpleStruct {
    char c;
    std::string str;
};


int main () {
    std::map<std::string, std::string> m;
    auto fill = [&m](std::string_view name, const auto& value){
        m[std::string(name)] = value;
    };

    boost::pfr::for_each_field_with_name(SimpleStruct{ 'e', "test"}, fill);
    BOOST_TEST_EQ(m.size(), 2);
    BOOST_TEST_EQ(m["c"], "e");
    BOOST_TEST_EQ(m["str"], "test");

    return boost::report_errors();
}
