#include "shell.h"

/**
 * _reallocate_memory - return memory number tokens
 * 
 * @ptr: string
 * @size_ini: initial size ptr
 * @size_fin: final size ptr
 * 
 * Return: new_ptr (success)
 */

char *reallocate_memory(char *ptr, unsigned int size_ini, unsigned int size_fin)
{
	char *new_ptr;
	unsigned int tr;

	if (size_fin == 0 && ptr != NULL)
	{
		free(ptr);
		return (0);
	}

	if (size_ini == size_fin)
		return (ptr);

	if (ptr == NULL)
	{
		new_ptr = malloc(size_fin);
		if (new_ptr == NULL)
			return (0);
		else
			return (new_ptr);
	}

	new_ptr = malloc(size_fin);
	if (new_ptr == NULL)
		return (0);

	for (tr = 0; tr < size_ini && tr < size_fin; tr++)
		new_ptr[tr] = ptr[tr];
	free(ptr);

	return (new_ptr);
}

