#include "main.h"

/**
 * main - shell function
 *
 * Return: exit status
 */
int main(void)
{
	char *input = NULL, **input_tokenized = {NULL};
	char *dir = NULL, *full_path = NULL;
	size_t size = 0;
	ssize_t getline_input = 0;
	int shell_mode;

	shell_mode = isatty(STDIN_FILENO); /*checks for shell mode*/
	while (1)
	{
		if (shell_mode == 1) /*if interactive mode, print prompt*/
			printf("♡ ");
		getline_input = getline(&input, &size, stdin); /*store imput*/
		if (getline_input == -1) /*if "ctrl + d"*/
		{ free(input);
			if (shell_mode == 1)
				printf("\n"), exit(1);
			exit(0); }
		if (strcmp(input, "exit\n") == 0) /*if input is "exit"*/
		{ free(input);
			break; }
		dir = _getenv("PATH"); /*gets the whole PATH env*/
		if (!dir)
			free(input), perror("Error"), exit(127);

		input_tokenized = tokenize(input); /*input tokenization for execution*/
		if (input_tokenized[0] == NULL)
			continue;

		if (access(input_tokenized[0], F_OK) == 0) /*if input is func path*/
			_execve(input_tokenized[0], input_tokenized); /*execute input*/
		else /*in case func path needs to be retrieved*/
		{ full_path = _which(dir, input_tokenized); /*search func path*/
		if (full_path == NULL) /*if input is not a func*/
		{ free(input_tokenized), perror("Error");
			continue; }
		_execve(full_path, input_tokenized); /*execute func with full path*/
		free(full_path); }
		free(input_tokenized);
	} return (0);
}
