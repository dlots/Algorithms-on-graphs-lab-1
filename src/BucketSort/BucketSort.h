#ifndef _BUCKET_SORT_H_
#define _BUCKET_SORT_H_

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

#include <vector>
using namespace std;

struct bucket_item
{
    bucket_item(uint64_t value, uint64_t index) :
        value(value),
        index(index)
    {}

    uint64_t value;
    uint64_t index;
};

void insertion_sort(std::vector<bucket_item>& bucket);

uint64_t* cpp_bucket_sort(uint64_t* arr, uint64_t len);

#ifdef __cplusplus
extern "C" {
#endif

uint64_t* bucket_sort(uint64_t* arr, uint64_t len);

#ifdef __cplusplus
}
#endif

#endif // _BUCKET_SORT_H_
