#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_shell.h"

/**
 * temoraeez_read_input - Reads the user's command input from standard input.
 * @size: size_t - The size of the buffer
 *
 * Return: char * - The user's command input
 */
char *temoraeez_read_input(size_t size)
{
	char *input = malloc(size);

	if (input == NULL)
	{
		perror("temoraeez_read_input");
		exit(EXIT_FAILURE);
	}

	if (fgets(input, size, stdin) == NULL)
	{
		perror("temoraeez_read_input");
		free(input);
		exit(EXIT_FAILURE);
	}

	input[strcspn(input, "\n")] = '\0';
	return (input);
}
