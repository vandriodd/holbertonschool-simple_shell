#include "main.h"

/**
 * _execve - executes a command
 * @path: command path
 * @args: command & arguments
 *
 * Return: void
 */
int _execve(char *path, char **args)
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
		if (execve(path, args, NULL) == -1)
		{
			free(path);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
	}
	return(WEXITSTATUS(status));
}