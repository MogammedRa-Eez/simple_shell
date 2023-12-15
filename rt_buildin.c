#include "shell.h"

/**
 * checkBuiltIn - checks command is a built-in
 * 
 * @command: command
 * 
 * Return: 0 or 1
 */

int checkBuiltIn(char *command)
{
	int tr;

	char *builtIns[] = {
		"exit", "cd", "env", "setenv", NULL};

	for (tr = 0; builtIns[tr]; tr++)
	{
		if (_strcmp(builtIns[tr], command) == 0)
		{
			return (1);
		}
	}

	return (0);
}

void handleBuiltInCommand(
	char **cmd, char **argv, int *status, int index, char **env)
{
	(void)index;
	if (_strcmp(cmd[0], "exit") == 0)
	{
		manageExit(cmd, argv, status, index);
	}
	else if (_strcmp(cmd[0], "env") == 0)
	{
		manageEnvironment(cmd, status, env);
	}
}

