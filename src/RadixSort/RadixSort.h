#ifndef _RADIX_SORT_H_
#define _RADIX_SORT_H_

#ifdef __cplusplus
extern "C" {
#endif

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <string.h>

const uint64_t mask1 = USHRT_MAX;
const uint64_t mask2 = mask1 << 16;
const uint64_t mask3 = mask2 << 16;
const uint64_t mask4 = mask3 << 16;

void count_sort(uint64_t** criteria_arr, uint64_t** indices_arr, uint64_t len, uint64_t mask);

uint64_t* radix_sort(uint64_t* arr, uint64_t len);

#ifdef __cplusplus
}
#endif

#endif // _RADIX_SORT_H_
