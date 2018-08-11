#include <cstddef>

auto parseHex(char const* p, size_t limit = ~0u) {
    struct { size_t val; char const* rest; } res = { 0, p };
    while (limit) {
        int v = *res.rest;
        if (v >= '0' && v <= '9')
            v = v - '0';
        else if (v >= 'A' && v <= 'F')
            v = 10 + v - 'A';
        else if (v >= 'a' && v <= 'f')
            v = 10 + v - 'a';
        else
            break;
        res.val = (res.val << 4) + v;
        --limit;
        ++res.rest;
    }
    return res;
}

#include <boost/pfr/precise/core.hpp>

auto parseLinePrefix(char const* line) {
     struct {
          size_t byteCount, address, recordType; char const* rest;
     } res;
     using namespace boost::pfr;
     tie (res.byteCount, line) = parseHex(line, 2);
     tie (res.address, line) = parseHex(line, 4);
     tie (res.recordType, line) = parseHex(line, 2);
     res.rest = line;
     return res;
}

#define check(expr) if (!(expr)) { fprintf(stderr, "Failed assertion: %s\n", #expr); ++errors; }

int main()
{
    int errors = 0;

    auto line = "0860E000616263646566000063";
    auto meta = parseLinePrefix(line);
    check(meta.byteCount == 8);
    check(meta.address == 24800);
    check(meta.recordType == 0);
    check(meta.rest == line + 8);

    size_t val;
    using namespace boost::pfr;

    tie (val, ignore) = parseHex("a73b");
    check(val == 42811);

    tie (ignore, line) = parseHex(line, 8);
    check(line == meta.rest);

    return errors;
}
