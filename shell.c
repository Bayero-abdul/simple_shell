#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include "shell.h"

void execute(char *line, char *argv[], char *env[]);

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
 * execute - executes the command
 * @line: command to run
 * @argv: list of strings
 * @env: list of strings
 * Return: void
 */
void execute(char *line, char *argv[], char *env[])
{
	pid_t child_pid;
	int status;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("./shell");
		exit(1);
	}
	else if (child_pid == 0)
	{
		if (execve(line, argv, env) == -1)
		{
			perror("./shell");
			exit(1);
		}
	}
	else
		wait(&status);
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

	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("#cisfun$ ");
		nread = getline(&line, &len, stdin);
		if (nread < 0)
			break;
		if (line[--nread] == '\n')
			line[nread] = '\0';
		if (line[0] == '\0')
			continue;
		argv[0] = line;
		if (stat(line, &st) == 0)
		{
			execute(line, argv, env);
		}
		else
			perror("./shell");
	}

	free(line);
	return (0);
}
