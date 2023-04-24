#include "main.h"

extern char **environ;

/**
 * _getenv - roams environ to get a specific env variable
 * @env: name of the env var to find
 *
 * Return: value of the env
 */
char *_getenv(const char *env)
{
	char *path = NULL, *val = NULL; /* *tmp = NULL, *command = NULL; */
	int i = 0;

	while (environ[i])
	{
		if (strncmp(environ[i], "PATH", 4) == 0)
		{
			path = strtok(environ[i], DELIM);
			val = strtok(NULL, DELIM);
			return (val);
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