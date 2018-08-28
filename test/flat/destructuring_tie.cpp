struct point {
   int x, y;
};

auto line(point a, point b) {
   struct {
      int timestamp;
      point a, b;
   } res = {123456, a, b};
   return res;
}

#define check(expr) if (!(expr)) { fprintf(stderr, "Failed assertion: %s\n", #expr); ++errors; }

#include <boost/pfr/flat/core.hpp>

#if BOOST_PFR_USE_CPP17 || BOOST_PFR_USE_LOOPHOLE

int main()
{
    int errors = 0;

    auto l = line({1, 2}, {3, 4});
    int t, a, b, c, d;
    using namespace boost::pfr;
    using std::ignore;

    flat_tie_from_structure (t, a, b, c, d) = l;
    check(t == 123456);
    check(a == 1);
    check(b == 2);
    check(c == 3);
    check(d == 4);

    flat_tie_from_structure (ignore, ignore, a, b, c) = l;
    check(a == 2);
    check(b == 3);
    check(c == 4);

    flat_tie_from_structure (ignore, a, b, c, ignore) = l;
    check(a == 1);
    check(b == 2);
    check(c == 3);

    return errors;
}

#else // C++14 without loophole
#include <iostream>
int main(int, char** argv) {
   std::cerr << argv[0] << ": Not supported in C++14 without reflection loophole.\n";
}
#endif
