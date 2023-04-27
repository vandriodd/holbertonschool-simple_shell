#include "main.h"

/**
 * main - entry point
 *
 * Return:
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
			free(input);
			/* free_array(input_tokenized); */ /* this free causes double free in tcache 2 */
			printf("exit\n");
			exit(1);
		}

		dir = _getenv("PATH"); /* gets the whole PATH env */
		input_tokenized = tokenize(input);
		full_path = _which(dir, input_tokenized);
		_execve(full_path, input_tokenized);
	}
}