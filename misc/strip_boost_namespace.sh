#!/bin/bash

# Copyright (c) 2021-2025 Antony Polukhin
#
# Distributed under the Boost Software License, Version 1.0. (See accompanying
# file LICENSE_1_0.txt or copy at http://www.boost.org/LICENSE_1_0.txt)

PFR_TEST_COMPILER=clang++-19

echo "***** Making target path"
TARGET_PATH="`dirname \"$0\"`/../../pfr_non_boost"
rm -rf ${TARGET_PATH}/*
mkdir -p ${TARGET_PATH}
TARGET_PATH=`cd "${TARGET_PATH}";pwd`

SOURCE_PATH="`dirname \"$0\"`/.."
SOURCE_PATH=`cd "${SOURCE_PATH}";pwd`

echo "***** Copying from ${SOURCE_PATH} to ${TARGET_PATH}"
cp -rf ${SOURCE_PATH}/* ${TARGET_PATH}

mv ${TARGET_PATH}/include/boost/* ${TARGET_PATH}/include/
rm -rf ${TARGET_PATH}/include/boost
rm -rf ${TARGET_PATH}/test
rm ${TARGET_PATH}/misc/strip_boost_namespace.sh
rm -rf ${TARGET_PATH}/meta

echo "***** Changing sources"
find ${TARGET_PATH} -type f | xargs sed -i \
        -e 's|namespace boost { ||g' \
        -e 's|namespace boost {||g' \
        -e 's|} // namespace boost::| // namespace |g' \
        \
        -e 's/::boost::pfr/::pfr/g' \
        -e 's/boost::pfr/pfr/g' \
        -e 's/BOOST_PFR_/PFR_/g' \
        -e 's|boost/pfr|pfr|g' \
        \
        -e 's/boost_pfr /pfr /g' \
        -e 's/boost_pfr_/pfr_/g' \
        -e 's/boost_pfr)/pfr)/g' \
        -e 's/Boost::pfr/pfr::pfr/g' \
        -e 's/BOOST_USE_MODULES/PFR_USE_MODULES/g' \
        -e 's|boost\.pfr;|pfr;|g' \

find ${TARGET_PATH}/doc -type f | xargs sed -i \
        -e 's|boost\.pfr\.|pfr.|g' \
        -e 's|boost\.pfr`|pfr`|g' \
        -e 's/boost_pfr\./pfr./g' \
        -e 's|Boost\.PFR|PFR|g' \

sed -i  's|# \[Boost.PFR\](https://boost.org/libs/pfr)|# [PFR](https://apolukhin.github.io/pfr_non_boost/)|g' ${TARGET_PATH}/README.md

echo -n "***** Testing: "
if ${PFR_TEST_COMPILER} -std=c++2a -DPFR_ENABLE_GET_NAME_STATIC=1 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/motivating_example0.cpp && ./a.out > /dev/null; then
    echo -n "OK"
else
    echo -n "FAIL"
    exit 2
fi
if ${PFR_TEST_COMPILER} -std=c++2a -DPFR_ENABLE_GET_NAME_STATIC=0 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/motivating_example0.cpp && ./a.out > /dev/null; then
    echo -n ", OK"
else
    echo -n ", FAIL"
    exit 3
fi

if ${PFR_TEST_COMPILER} -std=c++2a -DPFR_ENABLE_GET_NAME_STATIC=1 -DBOOST_PFR_USE_CPP17=1 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/get_name.cpp && ./a.out > /dev/null; then
    echo -n ", OK"
else
    echo -n ", FAIL"
    exit 4
fi

if ${PFR_TEST_COMPILER} -std=c++2a -DPFR_USE_LOOPHOLE=0 -DPFR_USE_CPP17=1 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/motivating_example0.cpp && ./a.out > /dev/null; then
    echo -n ", OK"
else
    echo -n ", FAIL"
    exit 5
fi
if ${PFR_TEST_COMPILER} -std=c++2a -DPFR_USE_LOOPHOLE=1 -DPFR_USE_CPP17=0 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/motivating_example0.cpp && ./a.out > /dev/null; then
    echo -n ", OK"
else
    echo -n ", FAIL"
    exit 6
fi

if ${PFR_TEST_COMPILER} -std=c++2a -DPFR_USE_LOOPHOLE=0 -DPFR_USE_CPP17=0 -I ${TARGET_PATH}/include/ ${TARGET_PATH}/example/get.cpp && ./a.out > /dev/null; then
    echo -n ", OK"
else
    echo -n ", FAIL"
    exit 7
fi

mkdir build_module || :
cd build_module
if cmake -DPFR_USE_MODULES=1 -DBUILD_TESTING=1 -GNinja -DCMAKE_CXX_COMPILER=${PFR_TEST_COMPILER} ${TARGET_PATH} && cmake --build .; then
    echo "Modules check OK"
else
    echo "Modules check FAIL"
    exit 8
fi
cd ..

rm -rf build_module || :
rm a.out || :

echo -e "\n***** Done"
