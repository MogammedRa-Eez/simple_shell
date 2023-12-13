#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/**
 * temoraeez_print - Function to print a string
 * @temoraeezstring: The string to be printed
 *
 * Return: void
 */

void temoraeez_print(const char *temoraeezstring)
{
	write(STDOUT_FILENO, temoraeezstring, strlen(temoraeezstring));
}
