#include "shell.h"

/**
 * freearray2D - Frees memory allocated for a 2D character array.
 * Frees memory allocated for a 2D array of characters.
 * @arr: Pointer to the 2D character array.
 */

void freearray2D(char **arr)
{
	int tr;

	if (!arr)
	return;

	for (tr = 0; arr[tr]; tr++)
	{
		free(arr[tr]);
		arr[tr] = NULL;
	}
	free(arr), arr = NULL;
}
