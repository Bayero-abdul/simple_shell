#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * handle_path - Handles command path
 * @arg_list: list of command line arguments
 * Return: command
 */
char *handle_path(char **arg_list)
{
	char str[64];
	char *cmd, *token;
	char bin[64] = "/bin/";
	struct stat st;

	cmd = arg_list[0];
	if (cmd == NULL || *cmd == '\0')
	{
		return (NULL);
	}

	strcpy(str, cmd);
	token = strtok(str, "/");
	printf("token: %s\n", token);

	if (token != NULL)
	{
		if (strcmp(token, "bin") != 0)
		{
			strcat(bin, arg_list[0]);
			printf("arg_list: %s\n", arg_list[0]);
			printf("bin: %s\n", bin);
			arg_list[0] = strdup(bin);
			if (stat(arg_list[0], &st) == 0)
			{
				printf("Hello Boss");
			}

			printf("arg_list[0]: %s\n", arg_list[0]);
			cmd = arg_list[0];
		}
	}
	return (cmd);
}
