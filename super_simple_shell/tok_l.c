#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 1024
/**
 * to_av - entry point
 */
char *to_av(*str)
{
    size_t size = SIZE, count = 0;
    char *buff = *token, **arr = NULL;

    while (printf("$ ") && getline(&buff, &size, stdin) != -1)
    {
        arr = malloc(sizeof(char *) * size);
        token = strtok(buff, " ");
        while (token)
        {
        }
    }
}
