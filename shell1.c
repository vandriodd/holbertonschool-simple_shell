#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 1024

int main(void)
{
    char *buffer, *cpy_buffer; /* **arr = NULL, *delim;*/
    size_t size = SIZE;        /*count;*/
    ssize_t line;

    buffer = malloc(sizeof(char *) * size);
    if (!buffer)
    {
        free(buffer);
        return (-1);
    }

    /* interactive mode */
    if (isatty(STDIN_FILENO) == 1)
    {
        printf("♡ ");
        line = getline(&buffer, &size, stdin);
        if (!buffer)
        {
            free(buffer);
            return (-1);
        }

        /* checks if the input is an EOF */
        if (line == -1)
        {
            free(buffer);
            return (-1);
        }
    }

    cpy_buffer = strdup(buffer);
    if (!cpy_buffer)
    {
        free(buffer);
        return (-1);
    }
    free(buffer);

    /* delim = strtok(cpy_buffer, " ");
    for (count = 0; delim; count++)
    {
        arr[count] = strdup(delim);
        if (!arr)
        {
            free(cpy_buffer);
            free(arr);
        }
        delim = strtok(NULL, " ");
    }
    */
    free(cpy_buffer); /*
 free(arr);*/
}

/*char **tokenize(char *str)
{
    size_t count;
    char **arr;
}*/