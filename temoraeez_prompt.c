#include <unistd.h>
#include "simple_shell.h"

/**
 * temoraeez_prompt - function to prompt user input
 *
 * Return: User input
 */

void temoraeez_prompt(void)
{
	write(STDOUT_FILENO, "funshell$ ", 10);
}
