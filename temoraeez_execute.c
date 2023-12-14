#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * temoraeez_execute - Executes the given command.
 * @args: Array of strings containing the command and its arguments.
 *
 * Return: Nothing.
 */

void temoraeez_execute(char **args)
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == 0)
	{

		if (execvp(args[0], args) == -1)
		{
			perror("Command not found");
			exit(EXIT_FAILURE);
		}
	}
	else if (pid < 0)
	{
		perror("Fork error");
	}
	else
	{
		waitpid(pid, &status, WUNTRACED);
	}
	free(args);
}

