#include "main.h"

/**
 * free_array - frees an array
 * @array: to be free
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