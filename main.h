#ifndef _MAIN_
#define _MAIN_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <dirent.h>
#include <sys/stat.h>
#include <stdarg.h>
#include <signal.h>

void process_line(char *cmd_line, size_t size, int cmd_count, char **av);
void create_pid(char **arrs, char *line, int count, char **av);
char **get_token(char *cmd_line, const char *delim, int token_len);
char **token_arr(int token_len, char *cmd_line, const char *delim);
int count_token(char *cmd_line, const char *delim);
char **path_token(int index, char *str);
char *search_dir(char **path_tokens, char *cmd);
char *build_path(char *dir, char *cmd);
char *gets_path(char *cmd);
int find_path(char *str);
int _strlen(char *str);
void _free_double(char **mem);
void _free_single(int p, ...);
void p_error(char *av, int count, char *cmd);
void exec_error(char *av, int count, char *tmp_cmd);
int print_num(int n);

extern char **environ;

/**
 * struct built_in - Defines the builtins functions.
 * @b_name: The name of the build in command.
 * @func: A pointer to the right builtin function.
 */
typedef struct built_in
{
	char *b_name;
	void (*func)(char *);
} builtin_f;

void cd_b(char *cmd_line);
void env_b(__attribute__((unused))char *cmd_line);
void (*check_builtins(char *str))(char *str);
void exit_b(char *line);
int built_in(char **cmd, char *cmd_line);
int _putchar(char c);
int print_num(int n);
int _strcmp(char *s1, char *s2);
char *_strdup(char *src);
void print_str(char *str, int new_line);


#endif
