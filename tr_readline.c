#include "shell.h"

/**
 * tr_readline - Read a line of input from the user.
 *
 * Return: A pointer to the line of input, or NULL
 */

char *tr_readline(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
	{
		perror("getline");
		return (NULL);
	}

	if (nread > 0 && line[nread - 1] == '\n')
	{
		line[nread - 1] = '\0';
	}

	return (line);
}
