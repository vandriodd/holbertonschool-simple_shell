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

	copy_path = strdup(env_value);/*copy env var for further tokenization*/
	if (!copy_path) /*malloc error return*/
	{
		free(copy_path);
		perror("Error");
		exit(1);
	}

	token = strtok(copy_path, DELIM); /*first tokenization*/
	value = malloc(sizeof(char) * (strlen(env_value) + strlen(command[0])) + 2);

	while (token) /*tries to create a full path for further execution*/
	{
		strcpy(value, token);
		strcat(value, "/");
		strcat(value, command[0]); /* concats the command to the path */

		if (!value) /*in case concatenization fails*/
		{
			free(copy_path);
			return (NULL);
		}

		if (access(value, F_OK) == 0) /*in case full function path exist*/
		{
			free(copy_path);
			return (value);
		}

		token = NULL;
		token = strtok(NULL, DELIM); /*continues tokenization*/
	}
	free(copy_path);
	free(value);
	free(token);
	return (NULL); /*in case no func full path is found*/
}
