#include "shell.h"

/**
 * _tokenize_string - break/split string
 * @buffer: string
 * @delimiter: char for delimit
 * Return: token value
 */

char **tokenize_string(char *buffer, char *delimiter)
{
	char **token = NULL;
	size_t tr = 0;
	unsigned int max_count = 10;

	if (buffer == NULL)
		return (NULL);
	token = malloc(sizeof(char *) * max_count);

	if (token == NULL)
		return (NULL);

	while ((token[tr] = strtok(buffer, delimiter)) != NULL)
	{
		tr++;
		if (tr == max_count)
		{
	
			if (token == NULL)
				return (NULL);
		}
		buffer = NULL;
	}
	return (token);
}
