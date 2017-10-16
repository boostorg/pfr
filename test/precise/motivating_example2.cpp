#include <iostream>
#include "boost/pfr/precise.hpp"

struct my_struct { // no ostream operator defined!
    std::string s;
    int i;
};

int main() {
#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE
    using namespace boost::pfr::ops; // C++17 out-of-the-box ostream operators for aggregate initializables!

    my_struct s{{"Das ist fantastisch!"}, 100};
    std::cout << "my_struct has " << boost::pfr::tuple_size<my_struct>::value
        << " fields: " << s << "\n";
#endif
}
