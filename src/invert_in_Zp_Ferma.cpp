#define __STDC_FORMAT_MACROS

#include <stdio.h>
#include <limits.h>
#include <stdint.h>
#include <inttypes.h>
#include <math.h>
#include <random>
#include <bitset>
#include <iostream>
using namespace std;

uint64_t fast_pow_mod(uint64_t base, uint64_t C, uint64_t mod)
{
    uint64_t last_pow;
    vector<uint64_t> result_pows;
    //std::cout << std::bitset<64>(C) << endl;
    uint64_t pow_2 = 1;
    //uint64_t pow_2_mod = base % mod;
    uint64_t result = 1;

    last_pow = base % mod;
    if ((C & pow_2) != 0)
    {
        result_pows.push_back(last_pow);
        //std::cout << std::bitset<64>(pow_2) << std::endl;
        //cout << pow_2 << endl;
    }

    pow_2 <<= 1;

    for (size_t i = 0; i < 63; ++i)
    {
        last_pow = (last_pow * last_pow) % mod;
        if ((C & pow_2) != 0)
        {
            //std::cout << std::bitset<64>(pow_2) << std::endl;
            //cout << pow_2 << endl;
            //result *= pow_2_mod;
            result_pows.push_back(last_pow);
        }
        pow_2 <<= 1;
    }

    //cout << endl;

    for (auto pow : result_pows)
    {
        //cout << pow << endl;
        result = (result * pow) % mod;
        //cout << result << endl << endl;
    }

    return result;
}

bool ferma_test(uint64_t number)
{
    if (number == 1)
    {
        return false;
    }

    std::random_device rd;
    std::mt19937 mersenne(rd());
    std::uniform_int_distribution<uint64_t> rand_int(1, USHRT_MAX);

    for (size_t i = 0; i < 100; )
    {
        uint64_t random_number = rand_int(mersenne);

        if (random_number % number == 0)
        {
            continue;
        }

        uint64_t a = fast_pow_mod(random_number,number - 1, number);

        //if (fast_pow_mod(random_number,number - 1, number) != 1)
        if (a != 1)
        {
            return false;
        }

        ++i;
    }

    return true;
}

uint64_t invert_Ferma(uint64_t p, uint64_t x)
{
    if (ferma_test(p))
    {
        return (fast_pow_mod(x, p-2, p));
    }
    else
    {
        return 0;
    }
}

int main()
{
    //uint64_t number = 53653;
    uint64_t number = INT_MAX;

    cout << endl << invert_Ferma(2147483647, 100);
}