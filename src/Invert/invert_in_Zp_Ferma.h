#pragma once

#include <limits.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <random>

#define __STDC_FORMAT_MACROS
using namespace std;

// Bitwise left-to-right fast modulo exponentiation 
uint64_t fast_pow_mod(uint64_t base, uint64_t C, uint64_t mod);

bool ferma_test(uint64_t number);

uint64_t cpp_invert_in_Zp_Ferma(uint64_t p, uint64_t x);

#ifdef __cplusplus
extern "C" {
#endif

uint64_t invert_in_Zp_Ferma(uint64_t p, uint64_t x);

#ifdef __cplusplus
}
#endif
