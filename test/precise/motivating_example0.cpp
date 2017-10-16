#include <iostream>
#include <string>
#include "boost/pfr/precise.hpp"

struct some_person {
    std::string name;
    unsigned birth_year;
};

int main() {
#if BOOST_PFR_USE_LOOPHOLE || BOOST_PFR_USE_CPP17
    some_person val{"Edgar Allan Poe", 1809};

    std::cout << boost::pfr::get<0>(val)
        << " was born in " << boost::pfr::get<1>(val);
#endif
}
