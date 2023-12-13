#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>



/*
 * Function: main
 * --------------------------
 * This function is the entry point of the shell program.
 * It displays a prompt, reads the user's command
 * and executes the command.
 *
 * returns: int - the exit status of the program
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
