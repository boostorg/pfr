#Precise and Flat Reflection (ex Magic Get, ex PODs Flat Reflection)

This C++14 library is meant for accessing structure elements by index and providing other std::tuple like methods for user defined types.


[Latest documentation](http://apolukhin.github.com/magic_get/index.html)

[Pre Boost version](https://github.com/apolukhin/magic_get/tree/pre_boost)

### Test results

Branches        | Build         | Tests coverage | More info
----------------|-------------- | -------------- |-----------
Develop:        | [![Build Status](https://travis-ci.org/apolukhin/magic_get.svg?branch=develop)](https://travis-ci.org/apolukhin/magic_get) [![Build status](https://ci.appveyor.com/api/projects/status/t6q6yhcabtk5b99l/branch/develop?svg=true)](https://ci.appveyor.com/project/apolukhin/boost-dll/branch/develop)  | [![Coverage Status](https://coveralls.io/repos/github/apolukhin/magic_get/badge.svg?branch=develop)](https://coveralls.io/github/apolukhin/magic_get?branch=develop) | [//]: # ([details...](http://www.boost.org/development/tests/develop/developer/pfr.html))
Master:         | [![Build Status](https://travis-ci.org/apolukhin/magic_get.svg?branch=master)](https://travis-ci.org/apolukhin/magic_get) [![Build status](https://ci.appveyor.com/api/projects/status/t6q6yhcabtk5b99l/branch/master?svg=true)](https://ci.appveyor.com/project/apolukhin/boost-dll/branch/master)  | [![Coverage Status](https://coveralls.io/repos/github/apolukhin/magic_get/badge.svg?branch=master)](https://coveralls.io/github/apolukhin/magic_get?branch=master) | [//]: # ([details...](http://www.boost.org/development/tests/master/developer/pfr.html))


### Motivating example
```c++
#include <iostream>
#include "boost/pfr.hpp"

struct my_struct { // no ostream operator defined!
    int i;
    char c;
    double d;
};

int main() {
    using namespace boost::pfr::ops; // out-of-the-box ostream operator for all PODs!

    my_struct s{100, 'H', 3.141593};
    std::cout << "my_struct has " << boost::pfr::tuple_size<my_struct>::value
        << " fields: " << s << "\n";
}

```

Outputs:
```
my_struct has 3 fields: {100, H, 3.14159}
```


### Requirements and Limitations

* C++14 compatible compiler (GCC-5.0+, Clang, ...)
* Static variables are ignored

C++14 limitations (C++17 fixes those):
* T must be constexpr aggregate initializable and must not contain references nor bitfields

### License

Distributed under the [Boost Software License, Version 1.0](http://boost.org/LICENSE_1_0.txt).
