#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * temoraeez_execute - Executes a command within the shell.
 * @command: The command to be executed.
 *
 * Return: No return value.
 *
 * This function creates a child process using fork() and executes
 * the provided command using execlp(). The parent process waits
 * for the child process to complete.
 */
void temoraeez_execute(const char *command)
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	else if (child_pid == 0)
	{
		/* Child process */
		if (execlp(command, command, (char *)NULL) == -1)
		{
			perror("execlp");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		/* Parent process */
		wait(NULL);
	}
}
