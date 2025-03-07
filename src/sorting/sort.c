#include <stdlib.h>
#include "../utils/utils.h"

void bubbleSort(int *arr)
{
    int n = DEFAULT_ARR_SIZE;
    int iterations = 0;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                iterations++;
            }
        }
    }
}