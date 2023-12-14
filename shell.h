#ifndef SHELL_H
#define SHELL_H 

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <sys/wait.h>

#define DELIM " \t\n"
extern char **environ;

char *temoraeez_read_line(void);
char **tr_tokenizer(char *thread);
int tr_execute(char **instruct, char **argv);

char *tr_strdup(const char *str);
int tr_strcmp(char *tr1, char *tr2);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

void freearray2D(char **arr);

#endif
