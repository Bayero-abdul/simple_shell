#include "shell.h"

/**
 * handle_path - Handles command path
 * @arg_list: list of command line arguments
 * @prog_name: pointer to program name
 * Return: command
 */
char *handle_path(char **arg_list, char *prog_name __attribute__((unused)))
{
	char *cmd, *path = NULL;
	struct stat st;

	cmd = arg_list[0];
	if (cmd == NULL || *cmd == '\0')
		return (NULL);
	
	if (stat(cmd, &st) == 0)
		return (cmd);
	
	path = _which(cmd);
	if (path != NULL)
	{
		free(cmd);
		return (path);
	}
	errno = 127;
	return (NULL);
}
