#include "shell.h"
/**
 * performExecution - execute a cmd
 * 
 * @cmd: command
 * @argv: arguments
 * @environment: environment
 * 
 * @indexNum: index
 * 
 * Return: status (success)
 */
int performExecution(char **cmd, char **argv, char **environment, int indexNum)
{
	char *fullCommand;
	pid_t childProcess;
	int status;

	fullCommand = _handlePath(cmd[0], environment);

	if (!fullCommand)
	{
		displayError(argv[0], cmd[0], indexNum);
		freeArray(cmd);
		return (127);
	}
	childProcess = fork();
	if (childProcess == 0)
	{
		if (execve(fullCommand, cmd, environment) == -1)
		{
			perror("execve");
		}
		free(fullCommand), fullCommand = NULL;
		freeArray(cmd);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (waitpid(childProcess, &status, 0) == -1)
		{
			perror("waitpid");
		}
		free(fullCommand), fullCommand = NULL;
		freeArray(cmd);
	}
	return (WEXITSTATUS(status));
}

