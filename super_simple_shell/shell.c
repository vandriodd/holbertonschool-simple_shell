#include "main.h"

extern char **environ;

/**
 * main - entry point
 *
 * Return:
 */
int main(void)
{
	char *input = NULL, **input_tokenized = {NULL}, *path = NULL, **a = NULL;
	size_t size = 0;

	while (1)
	{
		printf("♡ ");
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			return (-1);
		}

		input_tokenized = tokenize(input);

		path = malloc(sizeof(input_tokenized[0]) + 10); /* 10 = /usr/bin/ */
		path = _getenv(environ);
		if (!path)
		{
			free(input);
			free(path);
			return (-1);
		}
		a = tokenize(path);

		_execve(input_tokenized);
	}
}