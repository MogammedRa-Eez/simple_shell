#include "shell.h"

/**
 * tr_execute - Execute a command.
 *
 * @argv: The command to execute.
 *
 * Return: The exit status of the command.
 */

int tr_execute(char *argv[])
{
	pid_t pid;
	int status;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	if (pid == 0)
	{
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("execve");
			_exit(1);
		}
	}

	else
	{
		waitpid(pid, &status, 0);


		if (WIFEXITED(status) && WEXITSTATUS(status) != 0)
		{
			fprintf(stderr, "%s: %s\n", argv[0], strerror(WEXITSTATUS(status)));
		}
	}

	return (WEXITSTATUS(status));
}
