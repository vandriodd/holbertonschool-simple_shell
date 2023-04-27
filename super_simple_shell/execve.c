#include "main.h"

/**
 * _execve - executes a command
 * @path: command path
 * @args: command & arguments
 *
 * Return: void
 */
void _execve(char *path, char **args)
{
	int status = 0;
	pid_t pid = 0;

	pid = fork();

	if (pid == -1)
	{
		perror("Error");
		exit(1);
	}
	else if (pid == 0) /* child process */
	{
		execve(path, args, NULL);
	}
	else
	{
		wait(&status);
	}
	return;
}