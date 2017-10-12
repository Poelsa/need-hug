#! /bin/bash

DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" && pwd )"
cd $DIR

mkdir -p build;

cd build;
if [ $? -ne 0 ]; then
	exit 1;
fi

cmake -DNH_BUILD_TEST=on MAKE_BUILD_TYPE=DEBUG ..
if [ $? -ne 0 ]; then
	exit 1;
fi

make -j 4
if [ $? -ne 0 ]; then
	exit 1;
fi