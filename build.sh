#! /bin/bash

mkdir -p build;

cd build;
if [ $? -ne 0 ]; then
	exit 1;
fi

cmake ..
if [ $? -ne 0 ]; then
	exit 1;
fi

make -j 4
if [ $? -ne 0 ]; then
	exit 1;
fi