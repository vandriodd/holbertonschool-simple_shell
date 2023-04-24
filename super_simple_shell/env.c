#include <string.h>
#include <stdio.h>

#define DELIM " \n\t:="

extern char **environ;

char *_getenv(char *env)
{
    char *tmp, *command;
    int i = 0;

    while (environ[i])
    {
        tmp = strdup(environ[i]);
        tmp = strtok(tmp, DELIM);

        if (strcmp(tmp, environ[i]) == 0)
        {
            command = strdup(strtok(NULL, DELIM));
            free(tmp);
            return (command);
        }
        free(tmp);
    }
    return (NULL);
}