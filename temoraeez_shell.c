#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>
#include "simple_shell.h"

#define MAX COMMAND LENGTH "100"
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
			continue;
		}

		args = temoraeez_parse_input(line);
		if (args == NULL)
		{
			continue;
		}

		if (strcmp(args[0], "exit") == 0)
		{
			exit(EXIT_SUCCESS);
		}

		temoraeez_execute(args);

		free(line);
		free(args);
	}

	return (0);
}
