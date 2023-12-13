#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "simple_shell.h"


/**
 * temoraeez_prompt - Prints a prompt and reads user input in a loop.
 *
 * Return: Always 0.
 */
void temoraeez_prompt(void)
{
	temoraeez_print("temoraeez_shell$ ");
}
