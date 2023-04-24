#include "main.h"

extern char *environ;

/**
 * _execve - executes a command
 * @args: command & arguments
 *
 * Return: status of child process
 */
int _execve(char **args)
{
	int status = 0;

	if (fork() == 0) /* child process */
	{
		execve(args[0], args, NULL);
	}
	else
		wait(&status);

	return (WEXITSTATUS(status));
}