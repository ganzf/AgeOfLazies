#!/bin/bash

mkdir -p ../../build
cd ../../build
cmake ..
make -j6 package
gzip -d AoL-setup-1.0.tar.gz
tar xvf AoL-setup-1.0.tar
mkdir -p $HOME/.AgeOfLazies/lib/
cp AoL-setup-1.0/usr/local/*.so* $HOME/.AgeOfLazies/lib/
cp -r AoL-setup-1.0/usr/local/AgeOfLazies/* $HOME/.AgeOfLazies/
echo "export LD_LIBRARY_PATH=\"$LD_LIBRARY_PATH:$HOME/.AgeOfLazies/lib/\"" >> $HOME/.bashrc
echo "export LD_LIBRARY_PATH=\"$LD_LIBRARY_PATH:$HOME/.AgeOfLazies/lib/\"" >> $HOME/.zshrc 

source $HOME/.bashrc
source $HOME/.zshrc

