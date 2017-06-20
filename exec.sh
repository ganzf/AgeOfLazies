#!/bin/bash

rm -rf build
rm AgeOfLazies
mkdir build
cd build
cmake ..
make -j6
cp AgeOfLazies ..
cd ..
./AgeOfLazies
 
