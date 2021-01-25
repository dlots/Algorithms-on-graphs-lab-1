#include "invert_in_Zp_Ferma.h"

uint64_t fast_pow_mod(uint64_t base, uint64_t C, uint64_t mod)
{
    uint64_t last_pow;
    vector<uint64_t> result_pows;
    uint64_t pow_2 = 1;
    uint64_t result = 1;

    last_pow = base % mod;
    if ((C & pow_2) != 0)
    {
        result_pows.push_back(last_pow);
    }

    pow_2 <<= 1;

    for (size_t i = 0; i < 63; ++i)
    {
        last_pow = (last_pow * last_pow) % mod;
        if ((C & pow_2) != 0)
        {
            result_pows.push_back(last_pow);
        }
        pow_2 <<= 1;
    }

    for (auto pow : result_pows)
    {
        result = (result * pow) % mod;
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

        if (a != 1)
        {
            return false;
        }

        ++i;
    }

    return true;
}

uint64_t cpp_invert_in_Zp_Ferma(uint64_t p, uint64_t x)
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

uint64_t invert_in_Zp_Ferma(uint64_t p, uint64_t x)
{
    if ((p == 0) || (x == 0))
    {
        return 0;
    }

    return cpp_invert_in_Zp_Ferma(p, x);
}
