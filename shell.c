#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

#define SIZE 1024

int main(void)
{
    char *buffer, *delim, *cp_buff, **arr;
    size_t size = SIZE, count, wlen = 0;
    ssize_t line;

    printf("$ ");
    line = getline(&buffer, &size, stdin);

    while (buffer)
    {
        buffer = malloc(sizeof(char) * size);
        if (!buffer)
        {
            return (-1);
        }

        /* checks if the input is an EOF */
        if (line == -1)
        {
            return (-1);
        }
    }
    printf("%s", buffer);
    cp_buff = strdup(buffer);
    delim = strtok(cp_buff, " ");
    printf("%s", cp_buff);
    printf("%s\n", delim);
    while (delim)
    {
        delim = strtok(NULL, " ");
        printf("%s\n", delim);
        wlen++;
    }

    delim = strtok(buffer, " ");
    arr = malloc(sizeof(char *) * wlen);

    for (count = 0; count < wlen; count++)
    {
        arr[count] = strdup(delim);
        printf("%s\n", arr[count]);
        delim = strtok(NULL, " ");
    }
    return (0);
}