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
* prompt - prints a prompt
* Return: void
*/
void prompt(void)
{
	_puts("#cisfun$ ");
}

/**
* main - simple shell
* @argc: number of command arguments
* @argv: list of strings
* @env: list of strings
* Return: 0 if no errors
*/
int main(int argc, char *argv[], char *env[])
{
	char *line = NULL, **arg_list;
	char *cmd, *prog_name = argv[0];
	ssize_t nread;
	size_t len = 0;
	struct stat st;
	(void)env, (void)argv, (void)argc;

	signal(SIGINT, handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			prompt();

		nread = getline(&line, &len, stdin);
		if (nread == -1)
			break;

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		arg_list = parse_arg(line);
		cmd = arg_list[0];

		if (cmd == NULL || *cmd == '\0')
		{
			free(arg_list);
			continue;
		}

		if (stat(cmd, &st) == 0)
			execute(arg_list, prog_name);
		else
			perror(prog_name);
		
		free(arg_list);
		
	}
	if (isatty(STDIN_FILENO))
		_puts("\n");
	
	free(line);
	return (0);
}
