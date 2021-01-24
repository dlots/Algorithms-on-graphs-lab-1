#include "QuickSort.h"

quick_sort::quick_sort(size_t limit) : qsort_array_length_limit(limit)
{
    mersenne_engine = mt19937(chrono::steady_clock::now().time_since_epoch().count());
}

size_t quick_sort::partition(vector<item>& array, size_t a, size_t b, size_t pivot)
{
    size_t i = a;
    size_t j = a;

    swap(array[pivot], array[b - 1]);
    pivot = b - 1;

    while (j != pivot)
    {
        // X goes to the right part of the array by default.
        bool x_goes_left = false;

        // If X is less than pivot OR X is equal to pivot and left side is shorter
        // than the right, X goes to the left part of the array.
        if (( array[j].value < array[pivot].value ) ||
            (( array[j].value == array[pivot].value ) && ( (j - a) < (j - i) ))) {
            x_goes_left = true;
        }

        if (x_goes_left) {
            if (i != j) {
                swap(array[i], array[j]);
            }
            ++i;
        }
        ++j;
    }

    array.insert(array.begin() + i, array[pivot]);
    array.erase(array.begin() + pivot + 1);

    return i;
}

void quick_sort::qsort(vector<item>& array, size_t a, size_t b)
{
    if (b <= a)
    {
        return;
    }

    size_t pivot = 0;

    while ((b - a) >= qsort_array_length_limit)
    {
        if (b <= a)
        {
            return;
        }

        uniform_int_distribution<size_t> distribution(a, b - 1);
        pivot = distribution(mersenne_engine);

        pivot = partition(array, a, b, pivot);

        if ((pivot - a) <= (b - pivot - 1))
        {
            this->qsort(array, a, pivot);
            a = pivot + 1;
        }
        else
        {
            this->qsort(array, pivot + 1, b);
            b = pivot;
        }
    }

    insertion_sort(array, a, b);
}

uint64_t* cpp_qsort(uint64_t* arr, uint64_t len)
{
    vector<item> array;
    for (uint64_t i = 0; i < len; ++i)
    {
        array.push_back(item(arr[i], i));
    }

    size_t limit = len / 100;
    if (limit < 10)
    {
        limit = 10;
    }

    quick_sort sorter(limit);
    sorter.qsort(array, 0, array.size());

    uint64_t* indices = (uint64_t*)malloc(len * sizeof(uint64_t));
    if (indices == NULL)
    {
        exit(1);
    }
    memset(indices, 0, len * sizeof(uint64_t));

    size_t i = 0;
    for (const auto& item_ : array)
    {
        indices[i++] = item_.index;
    }

    return indices;
}

uint64_t* c_quick_sort(uint64_t* arr, uint64_t len)
{
    return cpp_qsort(arr, len);
}
