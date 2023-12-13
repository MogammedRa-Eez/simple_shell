#ifndef SIMPLE_SHELL_H
#define SIMPLE_SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>



void temoraeez_prompt(void);

char *temoraeez_read_input(size_t size);

void temoraeez_execute(const char *command);

void temoraeez_print(const char *temoraeezstring);

#endif
