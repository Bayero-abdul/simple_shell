#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "main.h"

/**
* main - simple shell
* Return: 0 if no errors
*/
int main(void)
{
	char *argv[] = { NULL, NULL }, *environ[] = { NULL }; 
	char *line = NULL, *cmd;
	size_t len = 0;
    ssize_t nread;
	struct stat st;
	pid_t pid;
    int status;

    do {	
		_puts("#cisfun$ ");
        nread = getline(&line, &len, stdin);
        if (nread == -1)
        {
            exit(1);
        }

        if (line[0] == '\n')
            continue;

        cmd = strtok(line, "\n");
		argv[0] = cmd;
		if (stat(cmd, &st) == 0)
		{
			pid = fork();
			if (pid == -1)
			{
				perror("./shell");
			}
			if (pid == 0)
			{
				if (execve(cmd, argv, environ) == -1)
					perror("./shell");
			}
			else
				wait(&status);
		}
		else
			perror("./shell");

	} while (status);

	free(line);
	exit(0);
}
