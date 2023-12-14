#include "simple_shell.h"

/**
 * main - Entry point for the simple shell.
 *
 *
 * Return: Always 0 (success).
 */

int main(void)
{
	char *line;
	char *argv[2];


	tr_display_prompt();

	while ((line = tr_readline()) != NULL)
	{
		argv[0] = strtok(line, " ");
		argv[1] = NULL;

		if (strcmp(argv[0], "exit") == 0)
		{
			break;
		}
		tr_execute(argv);

		tr_display_prompt();
	}

	free(line);

	return (0);
}
