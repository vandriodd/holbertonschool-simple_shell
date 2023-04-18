#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - splits a string
 *
 * Return: 0 on success
 */
int main(void)
{
	size_t size = 1024;
	char *buffer = malloc(size);
	char *token;

	while (buffer)
	{
		printf("$ ");
		getline(&buffer, &size, stdin);
		printf("%s", buffer);

		token = strtok(buffer, " ");
		while (token)
		{
			printf("%s\n", token);
			token = strtok(NULL, " ");
		}
	}

	return (0);
}
