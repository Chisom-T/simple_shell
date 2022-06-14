#ifndef _MAIN_
#define _MAIN_

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void process_line(char *cmd_line, size_t size, int cmd_count, char **av);
void create_pid(char **arrs, char *line, int count, char **av);
char **get_token(char *cmd_line, const char *delim, int token_len);
char **token_arr(int token_len, char *cmd_line, const char *delim);
int count_token(char *cmd_line, const char *delim);


#endif
