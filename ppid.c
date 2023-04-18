#include <stdio.h>
#include <unistd.h>

/**
 * main - prints the PID of the parent process
 *
 * Return: 0 on success
 */
int main()
{
	pid_t my_pid;

	my_pid = getpid();
	printf("Parent: %u\n", my_pid);
	return (0);
}
