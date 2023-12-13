#include <unistd.h>
#include "simple_shell.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 100
/**
 * temoraeez_prompt- function for user input
 *
 * Return: user input
 */

int temoraeez_prompt(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$cisfun ");
	fflush(stdout);

	while ((read = getline(&input, &len, stdin)) != -1)
	{
		printf("%s", input);
		printf("$cisfun ");
		fflush(stdout);
	}

	free(input);
	return (0);
}
