#include "main.h"
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

	token = strtok(copy_path, DELIM);
	value = malloc(sizeof(char) * (strlen(env_value) + strlen(command[0])) + 2);

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
