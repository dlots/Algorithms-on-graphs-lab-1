#include "RadixSort.h"

uint64_t get_single_16bit_digit(uint64_t number, uint64_t mask)
{
    uint64_t digit = number & mask;
    if (mask == mask2)
    {
        digit = digit >> 16;
    }
    else if (mask == mask3)
    {
        digit = digit >> 32;
    }
    else if (mask == mask4)
    {
        digit = digit >> 48;
    }
    return digit;
}

void count_sort(uint64_t** p_criteria_arr, uint64_t** p_indices_arr, uint64_t len, uint64_t mask)
{
    uint32_t* counting_arr = (uint32_t*)malloc(USHRT_MAX * sizeof(uint32_t));
    uint64_t* result_indices_arr = (uint64_t*)malloc(len * sizeof(uint64_t));
    uint64_t* result_criteria_arr = (uint64_t*)malloc(len * sizeof(uint64_t));
    if ((counting_arr == NULL) || (result_indices_arr == NULL) || (result_criteria_arr == NULL))
    {
        exit(1);
    }

    uint64_t* criteria_arr = *p_criteria_arr;
    uint64_t* indices_arr = *p_indices_arr;

    memset(counting_arr, 0, USHRT_MAX  * sizeof(uint32_t));
    memset(result_indices_arr, 0, len * sizeof(uint64_t));
    memset(result_criteria_arr, 0, len * sizeof(uint64_t));

    for (size_t i = 0; i < len; ++i)
    {
        uint64_t digit = get_single_16bit_digit(criteria_arr[i], mask);
        ++counting_arr[digit];
    }

    for (size_t i = 1; i < USHRT_MAX; ++i)
    {
        counting_arr[i] += counting_arr[i - 1];
    }

    for (int i = len - 1; i >= 0; --i)
    {
        uint64_t digit = get_single_16bit_digit(criteria_arr[i], mask);
        uint64_t position = counting_arr[digit] - 1;
        result_indices_arr[position] = indices_arr[i];
        result_criteria_arr[position] = criteria_arr[i];
        --counting_arr[digit];
    }

    free(indices_arr);

    //TODO:
    //crashes if this line is uncommented for some reason.
    //check what's wrong

    //free(criteria_arr);

    free(counting_arr);

    *p_indices_arr = result_indices_arr;
    *p_criteria_arr = result_criteria_arr;
}

uint64_t* radix_sort(uint64_t* arr, uint64_t len)
{
    uint64_t* indices = (uint64_t*)malloc(len * sizeof(uint64_t));
    if (indices == NULL)
    {
        exit(1);
    }
    for (size_t i = 0; i < len; ++i)
    {
        indices[i] = i;
    }

    count_sort(&arr, &indices, len, mask1);
    count_sort(&arr, &indices, len, mask2);
    count_sort(&arr, &indices, len, mask3);
    count_sort(&arr, &indices, len, mask4);

    return indices;
}
