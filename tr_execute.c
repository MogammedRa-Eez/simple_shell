#include "shell.h"
#include <sys/wait.h>

int tr_execute(char **instruct, char **argv)
{
    pid_t child;
    int status;

    child = fork();
    if (child == -1)
    {
        perror("fork");
        return -1;
    }
    else if (child == 0)
    {
        if (execve(instruct[0], instruct, environ) == -1)
        {
            perror(argv[0]);
            freearray2D(instruct);
            _exit(127);
        }
    }
    else
    {
        waitpid(child, &status, 0);
        freearray2D(instruct);
    }
    return WEXITSTATUS(status);
}

