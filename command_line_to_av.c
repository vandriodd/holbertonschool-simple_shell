#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - splits a string
 *
 * Return: a on success
 */
int main(void)
{
	size_t size = 1024;
	char *buffer = malloc(size);
	char *token;

	while (buffer)
	{
		printf("$ ");
		if (getline(&buffer, &size, stdin) == -1)
		{
			printf("\n");
			return (-1);
		}

		token = strtok(buffer, " ");
		while (token)
		{
			printf("%s\n", token);
			token = strtok(NULL, " ");
		}
	}

	return (0);
}
