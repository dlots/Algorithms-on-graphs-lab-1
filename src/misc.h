#pragma once

#include <vector>
#include <stdint.h>

using namespace std;

struct item
{
    item(uint64_t value, uint64_t index) :
        value(value),
        index(index)
    {}

    uint64_t value;
    uint64_t index;
};

void insertion_sort(vector<item>& arr, size_t a, size_t b);
