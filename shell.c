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
 * handler - Handles crtl c signal
 * @num: signal
 * Return: void
 */
void handler(int num)
{
	(void)num;
	_puts("\n#cisfun$ ");
	fflush(stdout);
}

/**
* main - simple shell
* Return: 0 if no errors
*/
int main(void)
{
	char *argv[] = { NULL, NULL}, *env[] = { NULL }, *line = NULL;
	size_t len = 0;
	ssize_t nread;
	struct stat st;
	int status;
	pid_t pid;

	signal(SIGINT, handler);
	while {
		if (isatty(STDIN_FILENO))
			_puts("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (read < 0)
			break;
		if (line[--nread] == '\n')
			line[nread] = '\0';
		if (line[0] == '\0')
			continue;
		argv[0] = line;
		if (stat(line, &st) == 0)
		{
			pid = fork();
			if (pid == -1)
				perror("./shell");
			if (pid == 0)
			{
				if (execve(line, argv, env) == -1)
					perror("./shell");
			}
			else
				wait(&status);
		}
		else
			perror("./shell");
	}
	if (isatty(STDIN_FILENO))
		_puts("\n");
	free(line);
	return (0);
}
