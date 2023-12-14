#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "simple_shell.h"

/**
 * main - Entry point for the simple shell
 *
 * Return: Always 0 on success
 */

int main(void)
{
	char *line;
	char **args;

	while (1)
	{
		temoraeez_prompt();
		line = temoraeez_read_input();

		if (line == NULL)
		{
			printf("\n");
			exit(EXIT_SUCCESS);
		}
		if (line[0] == '\0' || feof(stdin))
		{
			free(line);
			continue;
		}
		args = temoraeez_parse_input(line);
		if (args == NULL)
		{
			free(line);
			continue;
		}
		if (strcmp(args[0], "exit") == 0)
		{
			free(line);
			free(args);
			exit(EXIT_SUCCESS);
		}
		temoraeez_execute(args);

		free(line);
		free(args);
	}
	return (0);
}
