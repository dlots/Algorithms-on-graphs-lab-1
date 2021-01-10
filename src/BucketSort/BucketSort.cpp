#include "BucketSort.h"

void insertion_sort(std::vector<bucket_item>& bucket)
{
    for (size_t i = 1; i < bucket.size(); ++i)
    {
       bucket_item item = bucket[i];
       size_t j = i;
       while ((j > 0) && (bucket[j-1].value > item.value))
       {
          bucket[j] = bucket[j-1];
          --j;
       }
       bucket[j] = item;
    }
}

uint64_t* cpp_bucket_sort(uint64_t* arr, uint64_t len)
{
    std::vector<bucket_item> buckets[len];

    uint64_t min = ULONG_MAX;
    uint64_t max = 0;
    for (size_t i = 0; i < len; ++i)
    {
        if (arr[i] < min)
        {
            min = arr[i];
        }
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (size_t i = 0; i < len; ++i)
    {
        bucket_item item = bucket_item(arr[i], i);
        float normalized = (float)(arr[i] - min) / (max - min);
        uint64_t bucket_number = len * normalized;
        if (bucket_number < len)
        {
            buckets[bucket_number].push_back(item);
        }
        else
        {
            buckets[len - 1].push_back(item);
        }
    }

    for (auto bucket : buckets)
    {
        insertion_sort(bucket);
    }

    uint64_t* indices = (uint64_t*)malloc(len * sizeof(uint64_t));
    if (indices == NULL)
    {
        exit(1);
    }
    memset(indices, 0, len * sizeof(uint64_t));

    size_t i = 0;
    for (auto bucket : buckets)
    {
        for (auto item : bucket)
        {
            indices[i++] = item.index;
        }
    }

    return indices;
}

uint64_t* bucket_sort(uint64_t* arr, uint64_t len)
{
    return cpp_bucket_sort(arr, len);
}
