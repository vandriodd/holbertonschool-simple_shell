#include "main.h"

/**
 * tokenize - tokenizes a string
 * @str: string input
 *
 * Return: the string tokenized
 */
char **tokenize(char *str)
{
	char **str_tokenized = {NULL}, *token = NULL;
	size_t count = 0;
	int len = 0;

	len = len_counter(str);
	str_tokenized = malloc(sizeof(char *) * (len + 1)); /* + 1 = ptr NULL */
	if (!str_tokenized)
	{
		free(str_tokenized);
		perror("Error");
		exit(1);
	}

	token = strtok(str, DELIM);

	for (; token; count++) /* stores each token */
	{
		str_tokenized[count] = token;
		token = strtok(NULL, DELIM);
	}
	/* inserte NULL ptr */
	str_tokenized[count] = NULL;
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
			path = environ[i];
			return (path);
		}
		i++;
	}
	return (NULL);
}

/**
 * _which - show the full path of command
 * @env_value: value of path
 * @command: command input
 *
 * Return: the specific path of the command
 */
char *_which(char *env_value, char **command)
{
	char *copy_path = NULL, *token = NULL, *value = NULL;

	copy_path = strdup(env_value);
	if (!copy_path)
	{
		free(copy_path);
		perror("Error");
		exit(1);
	}

	token = strtok(copy_path, DELIM);                                            /* = */
	value = malloc(sizeof(char) * (strlen(env_value) + strlen(command[0])) + 2); /* + 2 = / & \0 */

	while (token)
	{
		strcpy(value, token);
		strcat(value, "/");
		strcat(value, command[0]); /* concats the command to the path */

		if (!value)
		{
			free(copy_path);
			return (NULL);
		}

		if (access(value, F_OK) == 0)
		{
			free(copy_path);
			return (value);
		}

		token = NULL;
		token = strtok(NULL, DELIM);
	}
	free(copy_path);
	free(value);
	free(token);
	return (NULL);
}