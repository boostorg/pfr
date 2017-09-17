// Copyright 2016-2017 Antony Polukhin

// Distributed under the Boost Software License, Version 1.0.
// (See the accompanying file LICENSE_1_0.txt
// or a copy at <http://www.boost.org/LICENSE_1_0.txt>.)

#include <cassert>
#include <iostream>
#include <unordered_set>
#include <set>

#include <boost/pfr.hpp>
#include <boost/type_index.hpp>


//[pfr_quick_examples_structures
struct foo {
    int integer;
    double real;
    
    void operator +=(int v) {
        integer += v * 10;
        real += v * 100;
    }
};

struct bar {
    char character;
    foo f;
};

bar var{'A', {777, 3.141593}};
//]
    
inline std::ostream& operator<<(std::ostream& os, const bar& b) {
    return os << '{' << b.character << ", {" << b.f.integer << ", " << b.f.real << "}}";
}

void test_examples() {
  {
    bar var{'A', {777, 3.141593}};
    
//[pfr_quick_examples_flat_functors_uset
    // no `std::hash<bar>` or `bar::operator==(const bar&)` defined
    std::unordered_set<bar, boost::pfr::flat_hash<bar>, boost::pfr::flat_equal_to<>> my_uset;
    my_uset.insert(var);
//]
  }

  {
    bar var{'A', {777, 3.141593}};
    
//[pfr_quick_examples_flat_functors_set
    // no `bar::operator<(const bar&)` defined
    std::set<bar, boost::pfr::flat_less<>> my_set;
    my_set.insert(var);
//]
  }

  {
//[pfr_quick_examples_flat_ops
    using namespace boost::pfr::flat_ops; // Defines comparisons
    assert((var < bar{'Z', {}} && var.f == foo{777, 3.141593}));
//]
    std::cout << "boost::pfr::flat_structure_tie(var) :\n" << var << '\n';
  }

#if BOOST_PFR_USE_CPP17
  {
//[pfr_quick_examples_ops
    struct test { std::string f1; std::string_view f2; };
    using namespace boost::pfr::ops; // Defines comparisons
    assert((test{"abc", ""} > test{"aaa", "zomg"}));
//]
  }
#endif

  {
    bar var{'A', {777, 3.141593}};
    
//[pfr_quick_examples_flat_for_each
    // incrementing each field on 1:
    boost::pfr::flat_for_each_field(var, [](auto& field) {
        field += 1;
    });
//]
    
    std::cout << "flat_for_each_field outputs:\n" << var << '\n';
  }
    
  {  
    bar var{'A', {777, 3.141593}};
    
//[pfr_quick_examples_for_each    
    // incrementing first field on 1 and calling foo::operator+= for second field:
    boost::pfr::for_each_field(var, [](auto& field) {
        field += 1;
    });
//]
    
    std::cout << "flat_for_each_field outputs:\n" << var << '\n';
  }



  
  {
    bar var{'A', {777, 3.141593}};
    
//[pfr_quick_examples_flat_for_each_idx  
    boost::pfr::flat_for_each_field(var, [](const auto& field, std::size_t idx) {
        std::cout << idx << ": " << boost::typeindex::type_id_runtime(field) << '\n';
    });
//]
  }
    
  {
    bar var{'A', {777, 3.141593}};

//[pfr_quick_examples_for_each_idx  
    boost::pfr::for_each_field(var, [](const auto& field, std::size_t idx) {
        std::cout << idx << ": " << boost::typeindex::type_id_runtime(field) << '\n';
    });
//]
  }


  {
//[pfr_quick_examples_tuple_size
    std::cout << "tuple_size: " << boost::pfr::tuple_size<bar>::value << '\n';
//]
  }
    
  {    
//[pfr_quick_examples_flat_tuple_size
    std::cout << "flat_tuple_size: " << boost::pfr::flat_tuple_size<bar>::value << '\n';
//]
  }

#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE
  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_get_1
    boost::pfr::get<1>(var) = foo{1, 2}; // C++17 is required
//]
    std::cout << "boost::pfr::get<1>(var) outputs:\n" << var << '\n';
  }
#endif

  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_flat_get_1
    boost::pfr::flat_get<1>(var) = 1;
//]
    std::cout << "boost::pfr::flat_get<1>(var) outputs:\n" << var << '\n';
  }
  
  
  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_get_2
    boost::pfr::get<1>(var.f) = 42.01;
//]
    std::cout << "boost::pfr::get<1>(var.f) outputs:\n" << var << '\n';
  }

  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_flat_get_2
    boost::pfr::flat_get<1>(var.f) = 42.01;
//]
    std::cout << "boost::pfr::flat_get<1>(var.f) outputs:\n" << var << '\n';
  }

#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE
  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_structure_to_tuple
    std::tuple<char, foo> t = boost::pfr::structure_to_tuple(var); // C++17 is required
    std::get<1>(t) = foo{1, 2};
//]
    std::cout << "boost::pfr::structure_to_tuple(var) :\n" << var << '\n';
  }
#endif

  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_flat_structure_to_tuple
    std::tuple<char, int, double> t = boost::pfr::flat_structure_to_tuple(var);
    std::get<0>(t) = 'C';
//]
    std::cout << "boost::pfr::flat_structure_to_tuple(var) :\n" << var << '\n';
  }

#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE
  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_structure_tie
    std::tuple<char&, foo&> t = boost::pfr::structure_tie(var); // C++17 is required
    std::get<1>(t) = foo{1, 2};
//]
    std::cout << "boost::pfr::structure_tie(var) :\n" << var << '\n';
  }
#endif

  {
    bar var{'A', {777, 3.141593}};
//[pfr_quick_examples_flat_structure_tie
    std::tuple<char&, int&, double&> t = boost::pfr::flat_structure_tie(var);
    std::get<0>(t) = 'C';
//]
    std::cout << "boost::pfr::flat_structure_tie(var) :\n" << var << '\n';
  }
} // void test_examples() {


int main() {
    test_examples();
}
