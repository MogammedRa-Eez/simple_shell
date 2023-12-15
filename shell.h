#ifndef SHELL_H
#define SHELL_H

#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <signal.h>

extern char **environ;

typedef struct variables
{
    char *buffer;
    char **array_tokens;
    char *program;
    int exit_s;
} vars_t;

typedef struct builtins
{
    char *name;
    int (*f)(vars_t *, int num_line, char **env);
} builtins_t;


char **tokenize_string(char *buffer, char *delimiter);
char *reallocate_memory(char *ptr, unsigned int size_ini, unsigned int size_fin);
int execute_command(vars_t *vars, int num, char **env);
char *get_command_path(char *cmd, char **env);
char *validate_command_path(char **tokens, char *cmd);
char *concatenate_strings(char *dest, char *src);
char *duplicate_string(char *str);
int compare_strings(char *s1, char *s2);
int find_builtin_command(vars_t *vars, int num, char **env);
int execute_builtin_env(vars_t *vars, int num_line, char **env);
int execute_builtin_exit(vars_t *vars, int num_line, char **env);
int calculate_string_length(char *s);
int calculate_integer_length(int n);
char *convert_integer_to_string(int num);
int parse_string_to_int(char *s);

#endif

