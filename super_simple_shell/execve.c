#include "main.h"

/**
 * _execve - executes a command
 * @args: command & arguments
 *
 * Return: status of child process
 */
int _execve(char **args)
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
		execve(args[0], args, NULL);
	}
	else
	{
		wait(&status);
	}
	return (WEXITSTATUS(status));
}