#include <sys/wait.h>
#include <unistd.h>

extern char **environ;

int _execve(char **args)
{
    int status = 0;

    if (fork() == 0) /* */
    {
        execve(args[0], args, environ);
    }
    else
        wait(&status);

    return (WEXITSTATUS(status));
}