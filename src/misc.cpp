#include "misc.h"

void insertion_sort(vector<item>& arr, size_t a, size_t b)
{
    for (size_t i = a + 1; i < b; ++i)
    {
        item item_ = arr[i];
        size_t j = i;
        while ((j > 0) && (arr[j-1].value > item_.value))
        {
            arr[j] = arr[j-1];
            --j;
        }
        arr[j] = item_;
    }
}
