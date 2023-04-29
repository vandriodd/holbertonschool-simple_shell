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

	len = len_counter(str); /*counts the amount of words in str*/
	str_tokenized = malloc(sizeof(char *) * (len + 1));
	if (!str_tokenized) /*malloc error case return*/
	{
		free(str_tokenized);
		perror("Error");
		exit(1);
	}

	token = strtok(str, DELIM); /*tokenizes str with delim defined in header*/

	for (; token; count++) /* stores each token */
	{
		str_tokenized[count] = token; /*store*/
		token = strtok(NULL, DELIM); /*generate new token*/
	}
	str_tokenized[count] = NULL; /*adds NULL at the end of token array*/
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

	while (environ[i]) /*searches in environ for the variable equal to env*/
	{
		if (strncmp(environ[i], env, 4) == 0) /*if env var found*/
		{
			path = environ[i];
			return (path); /*returns full env var requested*/
		}
		i++;
	}
	return (NULL); /*if no env var found*/
}
