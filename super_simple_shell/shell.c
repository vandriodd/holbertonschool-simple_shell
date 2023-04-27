#include "main.h"

/**
 * main - shell function
 *
 * Return: exit status
 */
int main(void)
{
	char *input = NULL, **input_tokenized = {NULL}, *dir = NULL, *full_path = NULL;
	size_t size = 0;

	while (1)
	{
		printf("♡ ");
		if (getline(&input, &size, stdin) == -1)
		{
			printf("exit\n");
			exit(1);
		}

		dir = _getenv("PATH"); /* gets the whole PATH env */
		if (!dir)
		{
			free(dir);
			perror("Error");
			exit(1);
		}

		input_tokenized = tokenize(input);

		full_path = _which(dir, input_tokenized);
		_execve(full_path, input_tokenized);

		free(full_path);
		free_array(input_tokenized);
	}
}