#include "shell.h"

/**
 * parse_string_to_int - return str no. in str
 * 
 * @s: string
 * 
 * Return: int num (success)
 */

int parse_string_to_int(char *s)
{
	int tr = 0;
	unsigned int num = 0;

	while (s[tr])
	{
		if (s[tr] >= '0' && s[tr] <= '9')
			num = (num * 10) + (s[tr] - '0');
		if (s[tr] > '9' || s[tr] < '0')
			return (-1);
		tr++;
	}
	return (num);
}
