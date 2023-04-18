#include <stdio.h>
#include <stdlib.h>

/**
 * main - prints all arguments without argc
 * @argc: argument count (unused)
 * @argv: argument vector
 *
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
	int i = 0;

	while (argv[i])
	{
		printf("%s", argv[i]);
		i++;
	}
	printf("\n");
	return (0);
}
