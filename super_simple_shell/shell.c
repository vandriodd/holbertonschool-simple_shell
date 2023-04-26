#include "main.h"

/**
 * main - entry point
 *
 * Return:
 */
int main(void)
{
	char *input = NULL, /*, **input_tokenized = {NULL}, */ *dir = NULL /*,*path = NULL*/;
	size_t size = 0;
	int /* len = 0, */ i = 0;

	while (1) /* pa corregir */
	{
		printf("♡ ");
		if (getline(&input, &size, stdin) == -1)
		{
			free(input);
			printf("exit\n");
			return (-1);
		}

		/* dir = _getenv("PATH");

		while (i < strlen(dir + 1))
		{
			printf("%d", dir[i]);
			i++;
		} */

		/* if (access(input, X_OK) == 0)
		{
			input_tokenized = tokenize(input);
		}
		else
		{
			input_tokenized = _which(input);
			len = strlen(input_tokenized);
			input_tokenized[len + 1] = '/';
			input_tokenized = strcat(input_tokenized, input);
			for (i = 0; input_tokenized; i++)
			{
				printf("%s", input_tokenized[i]);
			}
		}
		_execve(input_tokenized);
		*/
	}
}