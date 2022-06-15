#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
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
	char *line = NULL, *argv[] = { NULL, NULL, NULL, NULL }, *env[] = {NULL};
	size_t len = 0;
	ssize_t nread;
	pid_t child_pid;
	int status;

	while (1)
	{
		_puts("cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			exit(EXIT_FAILURE);
		}
		if (line[--nread] == '\n')
		line[nread] = '\0';

		if (*line == '\0')
			continue;
		else
		{
			argv[0] = line;
			child_pid = fork();
			if (child_pid != 0)
				wait(&status);

			if (child_pid == 0)
			{
				if (execve(line, argv, env) == -1)
					perror("./shell");
			}
		}
	}

	free(line);
	return (0);
}
