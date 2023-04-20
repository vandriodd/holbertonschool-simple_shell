#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define SIZE 1024

char **tokenize(char *str);

/**
 */
int main(void)
{
    char *buffer = NULL, **argv;
    size_t size = SIZE;
    /*ssize_t line = 0;*/

    while (printf("♡ ") && getline(&buffer, &size, stdin) != -1)
    {
        argv = tokenize(buffer);

        while (*argv)
        {
            printf("%s", *argv++);
        }
    }
}

char **tokenize(char *str)
{
    size_t count = 0, size = SIZE;
    char **arr = NULL, *token;

    arr = malloc(sizeof(char *) * size);
    token = strtok(str, " ");
    while (token != NULL)
    {
        arr[count] = strdup(token);
        if (!arr)
        {
            free(str);
            exit(1);
        }
        token = strtok(NULL, " ");
        count++;
    }
    token = strtok(NULL, "\n");
    return (arr);
}