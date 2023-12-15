#include "shell.h"

/**
 * manageEnvironment - takes the environment cmd
 * 
 * @command: command
 * @status: status to exit with
 * @enviornment: environment
 * 
 * Return: void (success)
 */

void manageEnvironment(char **command, int *status, char **enviornment)
{
	int tr;

	for (tr = 0; enviornment[tr]; tr++)
	{
		write(STDOUT_FILENO, enviornment[tr], _strlen(enviornment[tr]));
		write(STDOUT_FILENO, "\n", 1);
	}

	freeArray(command);
	(*status) = 0;
}

/**
 * manageExit - manage exit cmd
 * 
 * @command: command to free
 * @status: to exit with
 * @argv: arguments
 * @index: index
 * 
 * Return: void (success)
 */

void manageExit(char **command, char **argv, int *status, int index)
{
	int exitWith = *status;

	if (command[1] && isPositive(command[1]))
	{
		exitWith = _atoi(command[1]);
	}
	else if (command[1] && !isPositive(command[1]))
	{
		displayErrorExit(argv[0], command[1], index);
		freeArray(command);
		(*status) = 2;
		return;
	}
	freeArray(command);
	exit(exitWith);
}

/**
 * _handlePath - handles the path
 * 
 * @cmd: command
 * @environment: environment
 * 
 * Return: path (success)
 */

char *_handlePath(char *cmd, char **environment)
{
	char *pathEnv, *pathEnvCopy, *fullCommand, *directory;
	struct stat state;
	int tr;

	for (tr = 0; cmd[tr]; tr++)
	{
		if (cmd[tr] == '/')
		{
			if (stat(cmd, &state) == 0)
				return (_strdup(cmd));
			return (NULL);
		}
	}
	pathEnv = _getEnvironment("PATH", environment);
	if (!pathEnv)
		return (NULL);

	pathEnvCopy = _strdup(pathEnv), directory = strtok(pathEnvCopy, ":");
	while (directory)
	{
		fullCommand = malloc(_strlen(directory) + _strlen(cmd) + 2);
		if (fullCommand)
		{
			_strcpy(fullCommand, directory), _strcat(fullCommand, "/"), _strcat(fullCommand, cmd);
			if (stat(fullCommand, &state) == 0)
			{
				free(pathEnvCopy);
				free(pathEnv);
				return (fullCommand);
			}
			free(fullCommand);
		}
		directory = strtok(NULL, ":");
	}
	free(pathEnvCopy);
	free(pathEnv);
	return (NULL);
}

