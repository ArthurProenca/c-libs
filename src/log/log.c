#include <stdio.h>
#include <time.h>
#include <stdarg.h>
#include "log.h"
#include <stdlib.h>
#include "../utils/utils.h"

char *ARR_TO_STR(int *arr)
{
    // Allocate memory for the string representation
    char *str = (char *)malloc(DEFAULT_ARR_SIZE * 4 + 3); // 3 for brackets and null terminator
    int offset = 0;

    // Add the opening bracket
    str[offset++] = '[';

    // Convert the array elements to a string
    for (int i = 0; i < DEFAULT_ARR_SIZE; i++)
    {
        offset += sprintf(str + offset, "%d", arr[i]);

        // Add a comma between elements except the last one
        if (i < DEFAULT_ARR_SIZE - 1)
        {
            str[offset++] = ',';
        } 
    }

    // Add the closing bracket and null terminator
    str[offset++] = ']';
    str[offset] = '\0';

    return str;
}

void LOG(char *msg, LogType logType, ...)
{
    time_t now;
    time(&now);

    char strLogType[6];

    switch (logType)
    {
    case ERROR:
        strLogType[0] = 'E';
        strLogType[1] = 'R';
        strLogType[2] = 'R';
        strLogType[3] = 'O';
        strLogType[4] = 'R';
        strLogType[5] = '\0';
        break;
    case WARN:
        strLogType[0] = 'W';
        strLogType[1] = 'A';
        strLogType[2] = 'R';
        strLogType[3] = 'N';
        strLogType[4] = '\0';
        break;
    case INFO:
        strLogType[0] = 'I';
        strLogType[1] = 'N';
        strLogType[2] = 'F';
        strLogType[3] = 'O';
        strLogType[4] = '\0';
        break;
    default:
        strLogType[0] = 'U';
        strLogType[1] = 'N';
        strLogType[2] = 'K';
        strLogType[3] = 'N';
        strLogType[4] = '\0';
        break;
    }

    struct tm *local_time = localtime(&now);

    va_list args;
    va_start(args, logType);

    char formatted_msg[512];
    vsnprintf(formatted_msg, sizeof(formatted_msg), msg, args);

    printf("[%02d/%02d/%d %02d:%02d:%02d] - [%s] - %s\n",
           local_time->tm_mday, local_time->tm_mon + 1, local_time->tm_year + 1900,
           local_time->tm_hour, local_time->tm_min, local_time->tm_sec, strLogType, formatted_msg);

    va_end(args);
}
