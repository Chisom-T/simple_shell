#include "main.h"

/**
 * process_line - Processes the cmd line with argumements
 * Also frees memory that is not longer needed
 * @cmd_line: param pointer to a string
 * @size: A holder for numbers of size_t. Will always be initilized to 0.
 * @cmd_count: param counter to keep track of how many cmds have been entered
 * @av: param for executable name
 */

void process_line(char *cmd_line, size_t size, int cmd_count, char **av)
{
	int i, token_len;
	ssize_t line_len;
	char **param_array, entry[] = "my_shell-$ ";
	const char *delim = "\n\t ";

	token_len = 0;
	write(STDOUT_FILENO, entry, _strlen(entry));
	line_len = getline(&cmd_line, &size, stdin);
	if (line_len != -1)
	{
		param_array = get_token(cmd_line, delim, token_len);
		if (param_array[0] == NULL)
		{
			_free_single(2, param_array, cmd_line);
			return;
		}
		i = built_in(param_array, cmd_line);
		if (i == -1)
			create_pid(param_array, cmd_line, cmd_count, av);
		for (i = 0; param_array[i] != NULL; i++)
			free(param_array[i]);
		_free_single(2, param_array, cmd_line);
	}
	else
		exit_b(cmd_line);
}
