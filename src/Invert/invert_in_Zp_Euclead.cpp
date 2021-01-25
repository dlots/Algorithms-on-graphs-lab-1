#include "invert_in_Zp_Euclead.h"

uint64_t cpp_invert_in_Zp_Euclead(uint64_t a, uint64_t b)
{
    if ((a == 0) || (b == 0))
    {
        return 0;
    }

    if (a < b)
    {
        swap(a,b);
    }
    int p = a;

    int j1 = 1;
    int j2 = 0;
    int x1 = 0;
    int x2 = 1;

    while (true)
    {
        int new_b = a % b;
        if (new_b == 0)
            break;

        int integer_divisor = a / b;

        int new_j2 = j1 - j2 * integer_divisor;
        j1 = j2;
        j2 = new_j2;

        int new_x2 = x1 - x2 * integer_divisor;
        x1 = x2;
        x2 = new_x2;

        a = b;
        b = new_b;
    }

    if (b == 1)
    {
        if (x2 < 0)
        {
            x2 = p + x2;
        }
        return x2;
    }
    else
    {
        return 0;
    }
}

uint64_t invert_in_Zp_Euclead(uint64_t p, uint64_t x)
{
    return cpp_invert_in_Zp_Euclead(p, x);
}
