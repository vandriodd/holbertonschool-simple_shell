#include "main.h"

/**
 * aaaaaaaaaaaaaaa
 */
void free_array(char **array)
{
    int i = 0;

    while (array[i])
    {
        free(array[i]);
        i++;
    }
    free(array);
}