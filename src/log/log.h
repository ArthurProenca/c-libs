#ifndef LOG_H
#define LOG_H

typedef enum
{
    INFO,  // Informational messages
    ERROR, // Error messages
    WARN   // Warning messages
} LogType;

void LOG(char *msg, LogType logType, ...);
char *ARR_TO_STR(int *arr);
#endif
