#include "shell.h"

/**
 * _duplicate_string - renew tokens
 * 
 * @str: string
 * 
 * Return: token value (success)
 */

char *duplicate_string(char *str)
{
	int n, tr = 0;
	char *s;

	while (str[tr])
		tr++;

	n = tr;

	s = malloc(n + 1);
	if (s == NULL)
		return (0);
	for (tr = 0; tr < n; tr++)
		s[tr] = str[tr];
	s[tr] = '\0';

	return (s);
}

