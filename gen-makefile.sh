#!/bin/sh

export CC=$(which clang)
export CXX=$(which clang++)
mkdir -p build
cd build
cmake ..

