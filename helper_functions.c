#include "main.h"

/**
 * _strlen - gets the lenght of a str
 * @str: param
 * Return: int
 */

int _strlen(char *str)
{
	int i;

	if (str == NULL)
		return (0);
	for (i = 0; str[i] != '\0'; i++)
		;

	return (i);
}

/**
 * _free_double - Free double pointer variables
 * @mem: address of the elements that need to be freed
 */

void _free_double(char **mem)
{
	int index;

	for (index = 0; mem[index] != NULL; index++)
		free(mem[index]);
	free(mem);
}

/**
 * _free_single - Will free a pointers to a string.
 * @p: The number of pointers to free.
 */

void _free_single(int p, ...)
{
	int i;
	char *str;
	va_list args;

	va_start(args, p);
	for (i = 0; i < p; i++)
	{
		str = va_arg(args, char*);
		if (str == NULL)
			str = "(nil)";
		free(str);
	}
	va_end(args);
}


/**
 * p_error - Prints a message error when a comand is not found
 * @count: A counter keeping track of the number of commands run on the shell.
 * @av: The name of the program running the shell.
 * @cmd: The specific command not being found.
 */
void p_error(char *av, int count, char *cmd)
{
	print_str(av, 1);
	print_str(": ", 1);
	print_num(count);
	print_str(": ", 1);
	print_str(cmd, 1);
}

/**
 * exec_error - Prints exec errors.
 * @av: The name of the program running the shell.
 * @count: Keeps track of how many commands have been entered.
 * @tmp_cmd: The command that filed.
 */

void exec_error(char *av, int count, char *tmp_cmd)
{
	p_error(av, count, tmp_cmd);
	print_str(": ", 1);
	perror("");
	exit(1);
}
