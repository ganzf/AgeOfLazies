#!/bin/bash

rm AgeOfLazies
rm build/AgeOfLazies
cd build
make -j6
cp AgeOfLazies ..
cd ..
