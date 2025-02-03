#include <stdlib.h>
#include <time.h>

int MIN_VALUE_OF_ARRAY = 0;
int MAX_VALUE_OF_ARRAY = 100;
int DEFAULT_ARR_SIZE = 10;

int *generateRandomArrayOfNumbers(int n)
{
    srand(time(NULL));

    int *randomArray = (int *)malloc(n * sizeof(int));
    if (randomArray == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        randomArray[i] = MIN_VALUE_OF_ARRAY + rand() % (MAX_VALUE_OF_ARRAY - MIN_VALUE_OF_ARRAY + 1);
    }
    return randomArray;
}