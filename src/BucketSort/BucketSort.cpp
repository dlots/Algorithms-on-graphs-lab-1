#include "BucketSort.h"
#include "../misc.h"

uint64_t* cpp_bucket_sort(uint64_t* arr, uint64_t len)
{
    vector<item> buckets[len];

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
        item item_ = item(arr[i], i);
        float normalized = (float)(arr[i] - min) / (max - min);
        uint64_t bucket_number = len * normalized;
        if (bucket_number < len)
        {
            buckets[bucket_number].push_back(item_);
        }
        else
        {
            buckets[len - 1].push_back(item_);
        }
    }

    for (auto& bucket : buckets)
    {
        insertion_sort(bucket, 0, bucket.size());
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
        for (auto item_ : bucket)
        {
            indices[i++] = item_.index;
        }
    }

    return indices;
}

uint64_t* bucket_sort(uint64_t* arr, uint64_t len)
{
    return cpp_bucket_sort(arr, len);
}
