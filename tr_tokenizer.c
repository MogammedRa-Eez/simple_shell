#include "shell.h"

/**
 * tr_tokenizer - Tokenizes a string using a delimiter.
 * @thread: Input string to be tokenized.
 *
 * Splits 'thread' into tokens using 'DELIM' as a separator.
 *
 * Return: Array of tokens on success, otherwise NULL.
 */

char **tr_tokenizer(char *thread)
{
	char *tr_token = NULL, *tr_tmp = NULL;
	char **instruct = NULL;
	int tr_cpt = 0, tr = 0;

	if (!thread)
		return (NULL);

	tr_tmp = tr_strdup(thread);

	tr_token = strtok(tr_tmp, DELIM);
	if (tr_token == NULL)
	{
		free(tr_tmp);
		return (NULL);
	}
	while (tr_token)
	{
		tr_cpt++;
		tr_token = strtok(NULL, DELIM);
	}
	free(tr_tmp);
	instruct = malloc(sizeof(char *) * (tr_cpt + 1));
	if (!instruct)
	{
		return (NULL);
	}

	tr_tmp = tr_strdup(thread);

	tr_token = strtok(tr_tmp, DELIM);
	while (tr_token)
	{
		instruct[tr] = tr_token;
		tr_token = strtok(NULL, DELIM);
		tr++;
	}
	free(tr_tmp);

	instruct[tr] = NULL;
	return (instruct);
}

