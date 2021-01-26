#!/bin/bash
g++ -fPIC -shared -o so/Bridges.so ./src/Bridges/Bridges.cpp ./src/BucketSort/BucketSort.cpp ./src/RadixSort/RadixSort.c ./src/QuickSort/QuickSort.cpp ./src/misc.cpp ; g++ -fPIC -shared -o so/Invert.so ./src/Invert/invert_in_Zp_Euclead.cpp ./src/Invert/invert_in_Zp_Ferma.cpp ; echo "Done"
