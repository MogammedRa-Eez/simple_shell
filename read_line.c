#include "shell.h"

/**
 * temoraeez_read_line - Reads a line of input from stdin.
 *
 * Reads a line of input from stdin
 *
 * Return: Pointer to the input line on success, otherwise NULL.
 */

char *temoraeez_read_line(void)
{
	char *thread = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
		write(STDOUT_FILENO, "$ ", 2);

	n = getline(&thread, &len, stdin);
	if (n == -1)
	{
		free(thread);
		return (NULL);
	}

	return (thread);
}
