#include <unistd.h>
#include "simple_shell.h"

void temoraeez_prompt(void)
{
	write(STDOUT_FILENO, "funshell$ ", 10);
}
