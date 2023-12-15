#include "shell.h"

/**
 * calculate_string_length - count lenght of string
 * @s: string
 * Return: value (success)
 */

int calculate_string_length(char *s)
{
	int len = 0;
	char *a;

	for (a = s; *a != '\0'; a++)
	{
		len += 1;
	}
	return (len);
}

/**
 * calculate_integer_length -  count number of integer
 * 
 * @n: string
 * Return: value(success)
 */

int calculate_integer_length(int n)
{
	int len;

	for (len = 0; n > 9 || n < -9; len++)
		n /= 10;

	return (len);
}


/**
 * _convert_integer_to_string - return tokens
 * @num: string
 * Return: value (success)
 */

char *convert_integer_to_string(int num)
{
	int tens, tr = 0, ind_neg = 0, num_len, k;
	char *num_str;

	tens = 1;
	num_len = calculate_integer_length(num);

	if (num < 0)
		ind_neg = 1;

	num_str = malloc(num_len + 2 + ind_neg);
	if (num_str == NULL)
		return (0);

	if (num < 0)
		num_str[tr++] = '-';

	for (k = 0; k < num_len; k++)
		tens *= 10;

	for (; k >= 0; k--)
	{
		if (num < 0)
			num_str[tr++] = (num / tens) * -1 + '0';
		else
			num_str[tr++] = (num / tens) + '0';
		num %= tens;
		tens /= 10;
	}
	num_str[tr] = '\0';
	return (num_str);
}
