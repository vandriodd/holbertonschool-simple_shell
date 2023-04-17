#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints "$ " & wait for the user to enter a command
 *
 * Return: 0 on success
 */
int main()
{
	size_t size = 1024;
	char *buffer = malloc(size);

	while (buffer)
	{
		printf("$ ");
		getline(&buffer, &size, stdin);
		printf("%s", buffer);
	}
	return (0);
}
