#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

/**
* main - simple shell
* @argc: number of command arguments
* @argv: list of strings
* @env: list of strings
* Return: 0 if no errors
*/
int main(int argc __attribute__((unused)), char *argv[], char *env[])
{
	char *line = NULL, **arg_list;
	char *cmd, *prog_name = argv[0];
	ssize_t nread;
	size_t cnt = 0, len = 0;
	struct stat st;
	(void)argv, (void)env;

	signal(SIGINT, handler);
	while (1)
	{
		cnt++;
		if (isatty(STDIN_FILENO))
			_puts("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;
		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';
		
		arg_list = split_words(line, ' ');
		if (arg_list == NULL)
			continue;
	
		cmd = handle_path(arg_list, prog_name);
                if (cmd == NULL || *cmd == '\0')
		{
			fprintf(stderr, "%s: %ld: %s: not found\n", prog_name, cnt, arg_list[0]);
		}
		else
		{
 
	                arg_list[0] = cmd;
			if (stat(cmd, &st) == 0)
			{
				execute(arg_list, prog_name);
			}
			else
			{
				perror(prog_name);
			}
		}
		free_array(arg_list);
	}
	if (isatty(STDIN_FILENO))
		_puts("\n");
	
	free(line);
	return (0);
}

/**
 * get_input - gets input
 * Return: input
 */
char *get_input(void)
{
	char *line = NULL;
	ssize_t nread;
	size_t len = 0;

	nread = getline(&line, &len, stdin);
	if (nread == -1)
		return (NULL);

	if (line[nread - 1] == '\n')
		line[nread - 1] = '\0';

	return (line);
}
