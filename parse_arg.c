#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell.h"

/**
 * parse_arg - parse input into arguments
 * @arg: input(string)
 * Return: command line arguments
 */
char **parse_arg(char *arg)
{
	char **arg_list;
	char *token;
	int i, j = 1;

	arg_list = malloc(sizeof(*arg_list) * j);
	if (arg_list == NULL)
		return (NULL);

	for (i = 0; ; arg = NULL, i++)
	{
		token = strtok(arg, " ");
		printf("token: %s\n", token);

		if (token == NULL)
			break;

		arg_list[i] = token;
		arg_list = realloc(arg_list, sizeof(*arg_list) * ++j);
		if (arg_list == NULL)
			return (NULL);
	}

	arg_list[i] = NULL;

	for (i = 0; arg_list[i] != NULL; i++)
	{
		printf("arg_list[%d]: %s\n", i, arg_list[i]);
	}
	return (arg_list);
}
