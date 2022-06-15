#include "main.h"

/**
 * exit_shell - exits the shell
 * @d_sh: data relevant (status and args)
 * Return: 0 on success.
 */

int exit_shell(shell_d *d_sh)
{
	unsigned int ustatus;
	int is_digit, str_len, big_number;

	if (d_sh->tokens[1] != NULL)
	{
		ustatus = _atoi(d_sh->tokens[1]);
		is_digit = _isdigit(d_sh->tokens[1]);
		str_len = _strlen(d_sh->tokens[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			get_err(d_sh, 2);
			d_sh->status = 2;
			return (1);
		}
		d_sh->status = (ustatus % 256);
	}
	return (0);
}
