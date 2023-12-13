#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>


/*
 * Function: temoraeez_print
 * --------------------------
 * This function prints a string to the standard output
 * temoraeezstring: const char * - the string to be printed
 *
 * returns: void
 */

void temoraeez_print(const char *temoraeezstring)
{
	write(STDOUT_FILENO, temoraeezstring, strlen(temoraeezstring));
}
