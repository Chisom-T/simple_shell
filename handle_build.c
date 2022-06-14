#include "main.h"

/**
 * cd_b - Changes the current working directory to the parameter passed to cd.
 * if no parameter is passed it will change directory to HOME.
 * @cmd_line: A string representing the input from the user.
 */

void cd_b(char *cmd_line)
{
	int i,token_len;
	char **p_arrs;
	const char *delim = "\n\t ";

	token_len = 0;
	p_arrs = get_token(cmd_line, delim, token_len);
	if (p_arrs[0] == NULL)
	{
		_free_single(2, p_arrs, cmd_line);
		return;
	}
	if (p_arrs[1] == NULL)
	{
		i = find_path("HOME");
		chdir((environ[i]) + 5);
	}
	else if (_strcmp(p_arrs[1], "-") == 0)
		print_str(p_arrs[1], 0);

	else
		chdir(p_arrs[1]);
	_free_double(p_arrs);
}

/**
 * env_b - Prints all the environmental variables in the current shell.
 * @cmd_line: A string representing the input from the user.
 */

void env_b(__attribute__((unused))char *cmd_line)
{
	int i, j;

	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; environ[i][j] != '\0'; j++)
			write(STDOUT_FILENO, &environ[i][j], 1);
		write(STDOUT_FILENO, "\n", 1);
	}
}

/**
 * exit_b - Exits the shell. After freeing allocated resources.
 * @line: A string representing the input from the user.
 */

void exit_b(char *cmd_line)
{
	free(cmd_line);
	print_str("\n", 1);
	exit(1);
}

/**
 * check_builtins - Finds the right function needed for execution.
 * @str: The name of the function that is needed.
 * Return: Upon sucess a pointer to a void function. Otherwise NULL.
 */

void (*check_builtins(char *str))(char *str)
{
	int i;

	builtin_f buildin[] = {
		{"exit", exit_b},
		{"env", env_b},
		{"cd", cd_b},
		{NULL, NULL}
	};

	for (i = 0; buildin[i].b_name != NULL; i++)
	{
		if (_strcmp(str, buildin[i].b_name) == 0)
		{
			return (buildin[i].func);
		}
	}
	return (NULL);
}

/**
 * built_in - Checks for builtin functions.
 * @command: An array of all the arguments passed to the shell.
 * @line: A string representing the input from the user.
 * Return: If function is found 0. Otherwise -1.
 */

int built_in(char **cmd, char *cmd_line)
{
	void (*build)(char *);

	build = check_builtins(cmd[0]);
	if (build == NULL)
		return (-1);
	if (_strcmp("exit", cmd[0]) == 0)
		_free_double(cmd);
	build(cmd_line);
	return (0);
}
