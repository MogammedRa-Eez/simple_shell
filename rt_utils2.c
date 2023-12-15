#include "shell.h"

/**
 * isPositiveNumber - checks if number is positive or not
 * 
 * @str: string
 * 
 * Return: 0 if positive or 1 if negative (success)
 */

int isPositiveNumber(char *str)
{
	int tr;

	if (!str)
	{
		return (0);
	}
	for (tr = 0; str[tr]; tr++)
	{
		if (str[tr] < '0' || str[tr] > '9')
		{
			return (0);
		}
	}
	return (1);
}

/**
 * _atoi - converts a string to an integer
 * 
 * @str: string
 * 
 * Return: integer (success)
 */

int _atoi(char *str)
{
	int tr, num = 0;

	for (tr = 0; str[tr]; tr++)
	{
		num *= 10;
		num += str[tr] - '0';
	}
	return (num);
}

/**
 * _getEnvironment - gets the value of an env
 * 
 * @variable: the name of the environment variable
 * @environment: the environment
 * 
 * Return: the value of the environment variable (success)
 */

char *_getEnvironment(char *variable, char **environment)
{
	char *tmp, *key, *value, *env;
	int tr;

	for (tr = 0; environment[tr]; tr++)
	{
		tmp = _strdup(environment[tr]);
		key = strtok(tmp, "=");
		if (_strcmp(key, variable) == 0)
		{
			value = strtok(NULL, "\n");
			env = _strdup(value);
			free(tmp), tmp = NULL;
			return (env);
		}
		free(tmp), tmp = NULL;
	}
	return (NULL);
}

/**
 * tokenize - splits a str into words
 * 
 * @line str: the input string
 * 
 * Return: a pointer to an array of strings
 */

char **tokenize(char *line)
{
	char *token = NULL, *temp = NULL;
	char **tokens = NULL;
	int tr = 0, rt = 0;

	if (!line)
	{
		return (NULL);
	};
	temp = _strdup(line);
	token = strtok(temp, WHITESPACE);
	if (token == NULL)
	{
		free(line), line = NULL;
		free(temp), temp = NULL;
		return (NULL);
	}
	while (token)
	{
		tr++;
		token = strtok(NULL, WHITESPACE);
	}
	free(temp), temp = NULL;

	tokens = malloc(sizeof(char *) * (tr + 1));
	if (!tokens)
	{
		free(line), line = NULL;
		return (NULL);
	}
	token = strtok(line, WHITESPACE);
	while (token)
	{
		tokens[rt] = _strdup(token);
		token = strtok(NULL, WHITESPACE);
		rt++;
	}
	free(line), line = NULL;
	tokens[rt] = NULL;
	return (tokens);
}

/**
 * readline - reads a line of text from STDIN
 * 
 * Return: string (success)
 */

char *readline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
	}
	read = getline(&line, &len, stdin);

	if (read == -1)
	{
		free(line), line = NULL;
	}

	return (line);
}
