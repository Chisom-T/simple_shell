#include "main.h"

/**
 * create_child - Create child process to execute another program
 * @arrs: Arr of pointers to strings
 * @cmd_line: contents of the readline func
 * @count: counter keeping track of how many cmds have been entered
 * @av: Name of the program running the shell
 */

void create_pid(char **arrs, char *line, int count, char **av)
{
	pid_t pid;
	int status, i, check;
	struct stat buffer;
	char *tmp_cmd, *cmd;

	pid = fork();
	if (pid == 0)
	{
		tmp_cmd = arrs[0];
		cmd = path_finder(arrs[0]);
		if (cmd == NULL)
		{
			/*checking for file in current directory*/
			check = stat(tmp_cmd, &buffer);
			if (check == -1)
			{
				error_printing(av[0], count, tmp_cmd);
				print_str(": not found", 0);
				single_free(2, line, tmp_cmd);
				for (i = 1; arrs[i]; i++)
					free(arrs[i]);
				free(arrs);
				exit(100);
			}
			/*file exist in cwd or has full path*/
			cmd = tmp_cmd;
		}
		param_array[0] = cmd;
		if (param_array[0] != NULL)
		{
			if (execve(arrs[0], arrs, environ) == -1)
				exec_error(av[0], count, tmp_cmd);
		}
	}
	else
		wait(&status);
}
