#include "shell.h"

/**
 * _concatenate_strings - return string number tokens
 * 
 * @dest: string
 * @src: char for delimit
 * 
 * Return: token value (success)
 */

char *concatenate_strings(char *dest, char *src)
{
	int len = 0, len2 = 0, total_len = 0, k = 0;

	while (dest[len])
	{
		len++;
		total_len++;
	}
	while (src[len2])
	{
		len2++;
		total_len++;
	}

	dest = reallocate_memory(dest, len, total_len + 1);

	while (src[k] != '\0')
		dest[len++] = src[k++];

	dest[len] = '\0';

	return (dest);
}

