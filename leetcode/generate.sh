#!/bin/bash

mkdir $1
cd $1
cp ../../template/solution.README.md README.md
gedit README.md
