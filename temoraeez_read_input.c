#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * temoraeez_read_input - Reads the user's command input from standard input.
 *
 *
 * Return: char * - The user's command input
 */

char *temoraeez_read_input(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	getline(&line, &bufsize, stdin);
	return (line);
}
