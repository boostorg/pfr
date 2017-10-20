# Precise and Flat Reflection (ex Magic Get, ex PODs Flat Reflection)

This C++14 library is meant for accessing structure elements by index and providing other std::tuple like methods for user defined types without any macro or boilerplate code.


[Latest documentation](http://apolukhin.github.com/magic_get/index.html)

### Test results

Branches        | Build         | Tests coverage | More info
----------------|-------------- | -------------- |-----------
Develop:        | [![Build Status](https://travis-ci.org/apolukhin/magic_get.svg?branch=develop)](https://travis-ci.org/apolukhin/magic_get) [![Build status](https://ci.appveyor.com/api/projects/status/1edm74h5id8qpr2k/branch/develop?svg=true)](https://ci.appveyor.com/project/apolukhin/magic-get/branch/develop) | [![Coverage Status](https://coveralls.io/repos/github/apolukhin/magic_get/badge.png?branch=develop)](https://coveralls.io/github/apolukhin/magic_get?branch=develop) | <!-- [details...](http://www.boost.org/development/tests/develop/developer/pfr.html)) -->
Master:         | [![Build Status](https://travis-ci.org/apolukhin/magic_get.svg?branch=master)](https://travis-ci.org/apolukhin/magic_get) [![Build status](https://ci.appveyor.com/api/projects/status/1edm74h5id8qpr2k/branch/master?svg=true)](https://ci.appveyor.com/project/apolukhin/magic-get/branch/master) | [![Coverage Status](https://coveralls.io/repos/github/apolukhin/magic_get/badge.png?branch=master)](https://coveralls.io/github/apolukhin/magic_get?branch=master) | <!-- [details...](http://www.boost.org/development/tests/master/developer/pfr.html)) -->

### Motivating Example #0
```c++
// requires: C++14
#include <iostream>
#include <string>
#include "boost/pfr/precise.hpp"

struct some_person {
    std::string name;
    unsigned birth_year;
};

int main() {
    some_person val{"Edgar Allan Poe", 1809};

    std::cout << boost::pfr::get<0>(val)                // No macro!
        << " was born in " << boost::pfr::get<1>(val);  // Works with any aggregate initializables!
}
```
Outputs:
```
Edgar Allan Poe was born in 1809
```


### Motivating Example #1
```c++
// requires: C++14
#include <iostream>
#include "boost/pfr/precise.hpp"

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

### Motivating Example #2

```c++
// requires: C++14
#include <iostream>
#include "boost/pfr/precise.hpp"

struct my_struct { // no ostream operator defined!
    std::string s;
    int i;
};

int main() {
    using namespace boost::pfr::ops; // out-of-the-box ostream operators for aggregate initializables!

    my_struct s{{"Das ist fantastisch!"}, 100};
    std::cout << "my_struct has " << boost::pfr::tuple_size<my_struct>::value
        << " fields: " << s << "\n";
}

```

Outputs:
```
my_struct has 2 fields: {"Das ist fantastisch!", 100}
```


### Requirements and Limitations

General:
* C++14 compatible compiler (GCC-5.0+, Clang, Visual Studio 2017 with /std:c++latest or /std:c++17, ...)
* Static variables are ignored
* T must be constexpr aggregate initializable and must not contain references nor bitfields

### License

Distributed under the [Boost Software License, Version 1.0](http://boost.org/LICENSE_1_0.txt).
