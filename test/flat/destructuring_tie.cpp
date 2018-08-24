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

int main()
{
    int errors = 0;

    auto l = line({1, 2}, {3, 4});
    int t, a, b, c, d;
    using namespace boost::pfr;

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