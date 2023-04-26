#include "main.h"

/**
 * len_counter -
 * @str:
 *
 * Return:
 */
int len_counter(char *str)
{
    int count = 0;
    char *token = NULL, *str_copy = NULL;

    str_copy = strdup(str);
    token = strtok(str_copy, DELIM);

    for (count = 1; token; count++) /* count = 1 cuz already tokenize one*/
    {
        token = strtok(NULL, DELIM);
    }
    return (count); /* amount of words */
}