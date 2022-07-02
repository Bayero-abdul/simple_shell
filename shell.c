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
		free(line);
		perror(argv[0]);

	}

	if (child_pid == 0)
	{
		if (execve(line, argv, env) == -1)
		{
			perror(argv[0]);
			exit(1);
		}
	}
	else
		wait(&status);
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
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	struct stat st;
	(void)env, (void)argv;

	if (argc < 1)
		return (-1);

	signal(SIGINT, handler);
	while (1)
	{
		if (isatty(STDIN_FILENO))
			_puts("#cisfun$ ");

		nread = getline(&line, &len, stdin);
		if (nread ==  -1)
			break;

		if (line[nread - 1] == '\n')
			line[nread - 1] = '\0';

		if (line[0] == '\0')
			continue;

		if (stat(line, &st) == 0)
		{
			execute(line, argv, env);
		}
		else
		{
			perror(argv[0]);
		}

	}

	if (isatty(STDIN_FILENO))
		_puts("\n");

	free(line);
	return (0);
}
