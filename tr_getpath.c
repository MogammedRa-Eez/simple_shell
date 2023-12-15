#include "shell.h"

/**
 * _validate_command_path - validate path for command
 * @tokens: strings token
 * @cmd: command call
 * Return: pointer char path
 */

char *validate_command_path(char **tokens, char *cmd)
{
	char *path;
	int tr = 0;

	while (tokens[tr] != NULL)
	{
		path = duplicate_string(tokens[tr]);
		path = concatenate_strings(path, "/");
		path = concatenate_strings(path, cmd);
		if (access(path, X_OK) == 0)
		{
			free(tokens);
			return (path);
		}
		tr++;
		free(path);
	}
	free(tokens);
	return (0);
}

/**
 * get_command_path - get path for command
 * @cmd: command call
 * @env: environment
 * Return: token value
 */

char *get_command_path(char *cmd, char **env)
{
	char *path, str[6], **tokens, *path_ok;
	int tr = 0, k, c;

	(void) env;
	while (environ[tr] != NULL)
	{
		for (k = 0; k < 5; k++)
			str[k] = environ[tr][k];
		str[k] = '\0';

		if (compare_strings(str, "PATH=") == 0)
			break;
		tr++;
	}

	if (environ[tr] != NULL)
	{
		c = k;
		while (environ[tr][k])
			k++;

		path = malloc(k - c + 1);
		if (path == NULL)
			return (0);
		while (environ[tr][c])
		{
			path[c - 5] = environ[tr][c];
			c++;
		}
		path[c - 5] = '\0';
		tokens = tokenize_string(path, ":");
		path_ok = validate_command_path(tokens, cmd);
		free(path);
		return (path_ok);
	}

	return (0);
}
