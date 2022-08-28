#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>

/**
 * handle_path - Handles command path
 * @arg_list: list of command line arguments
 * @prog_name: pointer to program name
 * Return: command
 */
char *handle_path(char **arg_list, char *prog_name)
{
	char *cmd;
	char bin[64] = "/bin/";
	struct stat st;

	cmd = arg_list[0];
	if (cmd == NULL || *cmd == '\0')
		return (NULL);

	if (cmd[0] == '/')
	{
		perror(prog_name);
		return (NULL);
	}

	strcat(bin, cmd);
	arg_list[0] = strdup(bin);
	cmd = arg_list[0];
	if (stat(cmd, &st) == -1)
	{
		free(cmd);
		perror(prog_name);
		return (NULL);
	}

	return (cmd);
}
