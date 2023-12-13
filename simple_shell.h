#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void temoraeez_prompt(void);
char *temoraeez_read_input(void);
char **temoraeez_parse_input(char *line);
void temoraeez_execute(char **args);



#endif
