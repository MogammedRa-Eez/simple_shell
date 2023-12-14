#include "shell.h"

/**
 * tr_strdup - Duplicates a string.
 * @str: String to be duplicated.
 *
 * Duplicates the input string 'str'.
 *
 * Return: Pointer to the duplicated string on success
 */

char *tr_strdup(const char *str)
{
	char *tr_ptr;
	int tr;
	int len = 0;

	if (str == NULL)
		return (NULL);
		while (*str != '\0')
		{
			len++;
			str++;
		}
		str = str - len;
		tr_ptr = malloc(sizeof(char) * (len + 1));
		if (tr_ptr == NULL)
		{
			return (NULL);
		}
		for (tr = 0; tr < len; tr++)
		{
			tr_ptr[tr] = str[tr];
		}
		tr_ptr[len] = '\0';
		return (tr_ptr);
}

/**
 * tr_strcmp - Compares two strings.
 * @tr1: First string to compare.
 * @tr2: Second string to compare.
 *
 * Compares two strings 'tr1' and 'tr2'.
 *
 * Return: 0 if strings are equal, positive value
 */
int tr_strcmp(char *tr1, char *tr2)
{
	int tr_cmp;


	tr_cmp = *tr1 - *tr2;
	while (*tr1 == *tr2)
	{
		if (*tr1 == '\0')
		{
			return (0);
		}
		tr1++;
		tr2++;
	}
	return (tr_cmp);
}
