#ifndef _MAIN_
#define _MAIN_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>
#include <limits.h>
#include <errno.h>
#include <fcntl.h>

void free_data(shell_d *d_sh);
void set_data(shell_d *d_sh, char **av);
void start_shell(shell_d *d_sh);
char *rm_comment(char *input);
char *get_line(int *i_eof);
ssize_t read_line(char **cmd_line, size_t *n, FILE *stream);

#define BUFSIZE 1024
#define TOK_BUFSIZE 128
#define TOK_DELIM " \t\r\n\a"
extern char **environ;

/**
 * struct s_data - struct that contains all relevant data on runtime
 * @av: list of argument
 * @input: cmd line inputs
 * @tokens: tokens of each separeted cmd
 * @status: last status of the shell
 * @counter: lines counter
 * @_environ: environment variable
 * @pid: process ID of the shell
 */

typedef struct s_data
{
	char **av;
	char *input;
	char **tokens;
	int status;
	int counter;
	char **_environ;
	char *pid;
} shell_d;

/**
 * struct sep_list_s - single linked list
 * @separator: ; | &
 * @next: next node
 * Description: single linked list to store separators
 */
typedef struct sep_list_s
{
	char separator;
	struct sep_list_s *next;
} sep_list;

/**
 * struct line_list_s - single linked list
 * @line: command line
 * @next: next node
 * Description: single linked list to store command lines
 */
typedef struct line_list_s
{
	char *line;
	struct line_list_s *next;
} line_list;


void go_next(sep_list **list_s, line_list **list_l, d_shell *d_sh);
int split_commands(d_shell *d_sh, char *input);
void add_nodes(sep_list **head_s, line_list **head_l, char *input);
char **get_token(char *input);
char *swap_char(char *input, int bool);
int get_err(d_shell *d_sh, int eval);
char *strcat_cd(d_shell *d_sh, char *msg, char *err, char *ver_str);
char *get_cd_err(d_shell *d_sh);
char *error404(data_shell *d_sh);
char *exit_error(d_shell *d_sh);
char *env_err(d_shell *d_sh);
char *error_path_126(d_shell *d_sh);


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
