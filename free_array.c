#include "shell.h"


void free_array(char **array)
{
	int i = 0;

	while(array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
	free(array[i]);
	free(array);
}
