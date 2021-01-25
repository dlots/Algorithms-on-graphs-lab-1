#pragma once

#include <inttypes.h>
#include <limits.h>
#include <algorithm>

using namespace std;

uint64_t cpp_invert_in_Zp_Euclead(uint64_t a, uint64_t b);

#ifdef __cplusplus
extern "C" {
#endif

uint64_t invert_in_Zp_Euclead(uint64_t p, uint64_t x);

#ifdef __cplusplus
}
#endif
