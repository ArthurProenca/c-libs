#include "utils/utils.h"
#include "sorting/sort.h"
#include "log/log.h"

int main()
{
    int *arr = generateRandomArrayOfNumbers(DEFAULT_ARR_SIZE);
    LOG("this %s number is greater than %i", ERROR, ARR_TO_STR(arr), 2);
    bubbleSort(arr);
}