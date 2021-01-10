#include "RadixSort.h"

int main(int argc, char const *argv[])
{
    printf("start\n");
    uint64_t* arr = (uint64_t*)malloc(5 * sizeof(uint64_t));
    printf("0 ok\n");
    arr[0] = 4;
    arr[1] = 3;
    arr[2] = 2;
    arr[3] = 0;
    arr[4] = 1;

    uint64_t* ind = radix_sort(arr, 5);

    return 0;
}
