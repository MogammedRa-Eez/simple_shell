#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

/**
 * main - Entry point of the shell program
 *
 * Return: 0 on successful completion
 */

int main(void)
{
	char *input;

	while (1)
	{
		temoraeez_prompt();
		input = temoraeez_read_input(128);
		temoraeez_execute(input);
		free(input);
	}
	return (0);
}
