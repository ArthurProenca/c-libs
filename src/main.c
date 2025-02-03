#include <stdio.h>
#include <stdlib.h>
#include "utils/utils.h"
#include "sorting/sort.h"

int main()
{
    int *arr = generateRandomArrayOfNumbers(DEFAULT_ARR_SIZE);

    showArray(arr);

    bubbleSort(arr);

    showArray(arr);
}