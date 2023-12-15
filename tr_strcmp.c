#include "shell.h"

/**
 * compare_strings - return compare string
 * 
 * @s1: string
 * @s2: char for delimit
 * 
 * Return: token value (success)
 */

int compare_strings(char *s1, char *s2)
{
	int tr;

	for (tr = 0; s1[tr]; tr++)
	{
		if (s1[tr] != s2[tr])
		return (1);
	}

	return (0);
}
