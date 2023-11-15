#include "shell.h"

/**
 * free_array - frees memory allocated to arrays
 * @args: array to free
 */
void free_array(char **args)
{
	int i = 0;

	if (args)
	{
		while (args[i] != NULL)
		{
			free(args[i]);
			i++;
		}
		free(args);
	}
}
