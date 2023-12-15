#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define WHITESPACE " \t\n"

/* =================== utils =========================*/
void freeArray(char **arr);
void displayError(char *name, char *cmd, int indexNum);
void displayErrorExit(char *name, char *cmd, int indexNum);
char *_intToAscii();
void reverseString(char *string, int length);
int isPositiveNumber(char *str);
int _atoi(char *str);

/* ================== utils2 ==========================*/
int isPositive(char *str);
int _atoi(char *str);
char *_getEnvironment(char *variable, char **environment);
char **tokenize(char *line);
char *readline(void);

/* ==================== strings =======================*/
int _strlen(char *string);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(const char *str);
int _strcmp(char *s1, char *s2);

/* ==================== execute ===================*/
int performExecution(char **cmd, char **argv, char **environment, int indexNum);

/* ===================== handlers =================*/
char *_handlePath(char *cmd, char **environment);
void manageExit(char **command, char **argv, int *status, int index);
void handleBuiltInCommand(
	char **command, char **argv, int *status, int index, char **enviornment);
void manageEnvironment(char **command, int *status, char **enviornment);
void printErrorOfExit(char *name, char *cmd, int indexNum);

/* ==================== myStrtok ===================*/
char *myStrtok(char *str, const char *delim);

/* ==================== myGetline ===================*/
ssize_t myGetline(char **linePtr, size_t *n, FILE *stream);

/* ==================== isBuiltIn =================*/
int checkBuiltIn(char *command);

#endif

