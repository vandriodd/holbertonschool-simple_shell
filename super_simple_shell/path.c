#include "main.h"

/**
 * tokenize - tokenizes a string
 * @str: string input
 *
 * Return: the string tokenized
 */
char **tokenize(char *str)
{
    char **str_tokenized = NULL, *token = NULL;
    size_t count = 0;
    int len = 0;

    len = len_counter(str);
    str_tokenized = malloc(sizeof(char *) * len);
    token = strtok(str, DELIM);

    for (; token; count++) /* stores each token */
    {
        str_tokenized[count] = token;
        token = strtok(NULL, DELIM);
    }
    return (str_tokenized);
}

/**
 * _getenv - roams environ to get a specific env variable
 * @env: name of the env var to find
 *
 * Return: value of the env
 */
char *_getenv(const char *env)
{
    char *path = NULL;
    int i = 0;

    while (environ[i])
    {
        if (strncmp(environ[i], env, 4) == 0)
        {
            path = environ[i + strlen(env) + 1];
            return (path);
        }
        i++;
    }
    return (NULL);

    /* while (environ[i])
    {
        tmp = strdup(&environ[i]);
        tmp = strtok(tmp, DELIM);

        if (strcmp(tmp, env) == 0) & for takes not just a char
        {
            command = strdup(strtok(NULL, DELIM));
            free(tmp);
            return (command);
        }
        i++;
        free(tmp);
    }
    return (NULL); */
}

/**
 * _which -
 *
 * Return:
 */
char **_which(char *env_value)
{
    char *token = NULL, *copy_val = NULL, **array = NULL;
    int i = 0;

    copy_val = strdup(env_value);
    token = malloc(sizeof(char *));
    if (!token)
    {
        free(copy_val);
        return (NULL);
    }
    token = strtok(copy_val, DELIM);
    array = malloc(sizeof(char *) * strlen(token));
    if (!array)
    {
        free(copy_val);
        return (NULL);
    }
    while (copy_val)
    {
        token = strtok(NULL, DELIM);
        array[i] = token;
        i++;
    }
    return (array);
}