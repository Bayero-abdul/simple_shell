#ifndef SHELL_H
#define SHELL_H

#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <errno.h>
#include "shell.h"

extern int errno;
extern char **environ;

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
char *handle_path(char **arg_list, char *prog_name, int *flag);

/* execute.c */
void execute(char **arg_list, char *prog_name, int *flag);

/* free_arg.c */
void free_arg(char **arg);

/* sig_handler.c */
void handler(int num);

int _getline(char **lineptr, FILE *stream);
char *_getenv(const char *name);
int count_words(char *str, char del);
char *_which(char *cmd);
char **split_words(char *str, char del);
void free_array(char **array);

#endif /* SHELL_H */
