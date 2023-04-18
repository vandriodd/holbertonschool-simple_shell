#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

/**
 * main - executes ls -l /tmp in 5 different child processes
 *
 * Return: 0 on success
 */
int main(void)
{
	pid_t p_pid;
	pid_t c_pid;
	int status;
	int i = 0;
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL};

	p_pid = getpid();

	while (i < 5 && c_pid)
	{
		c_pid = fork();
		if (c_pid == -1)
		{
			printf("Error");
			return (1);
		}
		wait(&status);
		i++;
	}

	if (c_pid == 0)
	{
		printf("Child: %u\n", getpid());
	}
	else
	{
		printf("Father: %u\n", p_pid);
	}

	if (execve(argv[0], argv, NULL) == -1)
		perror("Error");

	return (0);
}
