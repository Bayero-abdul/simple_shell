#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

/**
* execute - executes the command
* @arg_list: list of command line arguments
* @prog_name: name of program
* Return: void
*/
void execute(char **arg_list, char *prog_name, int *flag)
{
	char **env = environ;
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror(prog_name);
	}

	if (child_pid == 0)
	{
		if (execve(arg_list[0], arg_list, env) == -1)
		{
			perror(prog_name);
			exit(1);
		}
	}
	else
	{
		wait(&status);
		*flag = 0;
	}
}
