#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>

struct alias
{
	char *alias;
	char *real_name;
};

void prompt(void);
char *get_input(void);

/* puts.c */
int _puts(char *str);
int _putchar(char c);
int _strlen(char *str);

/* read_cmd.c */
char *read_cmd(void);

/* parse_arg.c */
char **parse_arg(char *arg);

/* handle_path */
char *handle_path(char **arg_list, char *prog_name);

/* execute.c */
void execute(char **arg_list, char *prog_name);

/* free_arg.c */
void free_arg(char **arg);

/* sig_handler.c */
void handler(int num);

int _getline(char **lineptr, FILE *stream);

#endif /* SHELL_H */
