#!/bin/bash

# Copyright (c) 2021 Antony Polukhin
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

TARGET_PATH="`dirname \"$0\"`/../../freestanding_pfr"
TARGET_PATH=`cd "${TARGET_PATH}";pwd`
SOURCE_PATH="`dirname \"$0\"`/.."
SOURCE_PATH=`cd "${SOURCE_PATH}";pwd`


echo "***** Copying from ${SOURCE_PATH} to ${TARGET_PATH}"
rm -rf ${TARGET_PATH}
mkdir ${TARGET_PATH}

cp -rf ${SOURCE_PATH}/* ${TARGET_PATH}

mv ${TARGET_PATH}/include/boost/* ${TARGET_PATH}/include/
rm -rf ${TARGET_PATH}/include/boost
rm -rf ${TARGET_PATH}/test

echo "***** Changing sources"
find ${TARGET_PATH} -type f | xargs sed -i 's|namespace boost { ||g'
find ${TARGET_PATH} -type f | xargs sed -i 's|namespace boost {||g'
find ${TARGET_PATH} -type f | xargs sed -i 's|} // namespace boost::| // namespace |g'

find ${TARGET_PATH} -type f | xargs sed -i 's/::boost::pfr/::pfr/g'
find ${TARGET_PATH} -type f | xargs sed -i 's/boost::pfr/pfr/g'
find ${TARGET_PATH} -type f | xargs sed -i 's/BOOST_PFR_/PFR_/g'
find ${TARGET_PATH} -type f | xargs sed -i 's|boost/pfr|pfr|g'

echo -n "***** Testing: "
if g++-9 -std=c++17 -DPFR_USE_LOOPHOLE=0 -DPFR_USE_CPP17=1 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/motivating_example0.cpp && ./a.out > /dev/null; then
    echo -n "OK"
else
    echo -n "FAIL"
    exit 2
fi
if g++-9 -std=c++17 -DPFR_USE_LOOPHOLE=1 -DPFR_USE_CPP17=0 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/motivating_example0.cpp && ./a.out > /dev/null; then
    echo -n ", OK"
else
    echo -n ", FAIL"
    exit 3
fi

if g++-9 -std=c++17 -DPFR_USE_LOOPHOLE=0 -DPFR_USE_CPP17=0 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/get.cpp && ./a.out > /dev/null; then
    echo -e ", OK"
else
    echo -e ", FAIL"
    exit 4
fi

rm a.out || :

echo "***** Done"
