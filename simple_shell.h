#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

#define READLINE_BUFFER_SIZE 1024
#define PROMPT "($) "

void tr_display_prompt(void);
char *tr_readline(void);
int tr_execute(char *argv[]);

#endif
