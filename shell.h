#ifndef SHELL_H
#define SHELL_H

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
char *handle_path(char **arg_list);

/* execute.c */
void execute(char **arg_list, char *prog_name);

/* free_arg.c */
void free_arg(char **arg);

/* sig_handler.c */
void handler(int num);

#endif /* SHELL_H */
