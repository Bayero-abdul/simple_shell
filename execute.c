#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>



/**
* execute - executes the command
* @line: command to run
* @argv: pointer to pointers of string
* @prog_name: name of program
* Return: void
*/
void execute(char **arg_list, char *prog_name)
{
	char **env = {NULL};
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
		wait(&status);
}
