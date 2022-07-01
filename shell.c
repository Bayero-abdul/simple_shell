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
	char *argv[] = { NULL, NULL, NULL, NULL }, *environ[] = { NULL };
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	struct stat st;
	int status;
	pid_t pid;

	do {
		printf("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (line[0] == '\n')
			continue;

		if (line[--nread] == '\n')
			line[nread] = '\0';

		argv[0] = line;
		if (stat(line, &st) == 0)
		{
			pid = fork();
			if (pid == 0)
			{
				if (execve(line, argv, environ) == -1)
					perror("./shell");
			}
			wait(&status);
		}
		else
			perror("./shell");
	} while (1);

	free(line);
	return (0);
}
