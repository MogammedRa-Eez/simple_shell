#include "shell.h"

/**
 * main - entry piont to the shell
 * 
 * @argv: arguments
 * @ac: arguments
 * @environment: envir
 * 
 * Return: 0 (success)
 */

int main(int ac, char **argv, char **environment)
{
	char *line, **tokens;
	int status = 0, indexNum = 0;
	(void)ac;

	while (1)
	{
		line = readline();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "$ ", 2);
			}
			return (status);
		}
		indexNum++;

		tokens = tokenize(line);
		if (!tokens)
		{
			continue;
		}

		if (checkBuiltIn(tokens[0]))
		{
			handleBuiltInCommand(tokens, argv, &status, indexNum, environment);
		}
		else
		{
			status = performExecution(tokens, argv, environment, indexNum);
		}
	}
}

