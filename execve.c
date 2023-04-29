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

	pid = fork(); /*forks the shell process*/

	if (pid == -1) /*in case of forking error*/
	{
		perror("Error");
		exit(1);
	}
	else if (pid == 0) /*child process*/
	{
		if (execve(path, args, environ) == -1)
		{
			free(path);
			free(args);
			exit(EXIT_FAILURE);
		}
	}
	else /*resume the father process when child process finishes*/
	{
		wait(&status);
	}
	return (WEXITSTATUS(status)); /*returns exit status of wait sys call*/
}
