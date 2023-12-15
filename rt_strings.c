#include "shell.h"

/**
 * _strlen - returns the len of a str
 * 
 * @string: string
 * 
 * Return: length (success)
 */

int _strlen(char *string)
{
	int tr;

	for (tr = 0; string[tr] != '\0'; tr++)
	{
		;
	}
	return (tr);
}

/**
 * _strcat - concatenate two str
 * 
 * @dest: first string
 * @src: second string
 * 
 * Return: concatenated str (success)
 */

char *_strcat(char *dest, char *src)
{
	int len = 0;
	int rt = 0;

	while (dest[len] != '\0')
	{
		len++;
	}
	while (src[rt] != '\0')
	{
		dest[len + rt] = src[rt];
		rt++;
	}
	dest[len + rt] = '\0';
	return (dest);
}

/**
 * *_strcpy - copies the str pointed
 * 
 * @dest: buffer
 * 
 * @src: string to be pointed by src
 * 
 * Return: the pointer to dest (success)
 */

char *_strcpy(char *dest, char *src)
{
	char *dest_start = dest;

	while (*src != '\0')
	{
		*dest = *src;
		src++;
		dest++;
	}
	*dest = '\0';
	return (dest_start);
}

/**
 * _strdup - Duplicate a str
 * 
 * @str: The string to duplicate
 * 
 * Return: duplicated string, or NULL
 */

char *_strdup(const char *str)
{
	char *ptr;
	int tr, len = 0;

	if (str == NULL)
		return (NULL);
	while (*str != '\0')
	{
		len++;
		str++;
	}
	str = str - len;
	ptr = malloc(sizeof(char) * (len + 1));
	if (ptr == NULL)
	{
		return (NULL);
	}
	for (tr = 0; tr <= len; tr++)
	{
		ptr[tr] = str[tr];
	}
	return (ptr);
}

/**
 * _strcmp - Compare two str
 * 
 * @s1: first string
 * @s2: second string
 * 
 * Return: compared str (success)
 */

int _strcmp(char *s1, char *s2)
{
	int tr;
	int dif = 0;

	for (tr = 0; s1[tr] != '\0' && s2[tr] != '\0'; tr++)
	{
		if (s1[tr] != s2[tr])
		{
			dif = s1[tr] - s2[tr];
			break;
		}
	}
	return (dif);
}

