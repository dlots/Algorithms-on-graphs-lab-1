#pragma once

#include <iostream>
#include <random>
#include <algorithm>
#include <ctime>
#include <chrono>
#include <cstring>
using namespace std;

#include "../misc.h"

class quick_sort
{
private:
    size_t qsort_array_length_limit;
    mt19937 mersenne_engine;
    size_t partition(vector<item>& array, size_t a, size_t b, size_t pivot);

public:
    quick_sort(size_t limit);
    void qsort(vector<item>& array, size_t a, size_t b);
};

uint64_t* cpp_qsort(uint64_t* arr, uint64_t len);

#ifdef __cplusplus
extern "C" {
#endif

uint64_t* c_quick_sort(uint64_t* arr, uint64_t len);

#ifdef __cplusplus
}
#endif
