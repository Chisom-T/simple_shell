#include "main.h"

/**
 * main - starts the simple shell programme
 * @ac: num of param (unused)
 * @av: arr of command list argument
 * Return: Always 0.
 */

int main(__attribute__((unused)) int ac, char **av)
{
	char *cmd_line;
	size_t size;
	int cmd_count;

	cmd_count = 0;
	signal(SIGINT, SIG_IGN);

	do {
		cmd_count++;
		cmd_line = NULL;
		size = 0;
		process_line(cmd_line, size, cmd_count, av);

	} while (1);

	return (0);
}
