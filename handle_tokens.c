#include "main.h"

/**
 * get_token - handles token functions, and make them more accessible
 * @cmd_line: A string containing the raw user input.
 * @delim: A constant string containing the desired delimeter to tokenize line.
 * @token_len: A holder for the amount of tokens in a string.
 * Return: an array of tokens representing the command
 */

char **get_token(char *cmd_line, const char *delim, int token_len)
{
	char **arrs;

	token_len = count_token(cmd_line, delim);
	if (token_len == -1)
	{
		free(cmd_line);
		return (NULL);
	}
	arrs = token_arr(token_len, cmd_line, delim);
	if (arrs == NULL)
	{
		free(cmd_line);
		return (NULL);
	}

	return (arrs);
}

/**
 * token_arr - Separates a cmd string into arrays of tokens
 * @token_len: An integer representing the amount of tokens in the array
 * @cmd_line: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: array of pointer to strings.
 */

char **token_arr(int token_len, char *cmd_line, const char *delim)
{
	int i;
	char **buffer, *token, *line_cp;

	line_cp = _strdup(cmd_line);
	buffer = malloc(sizeof(char *) * (token_len + 1));

	if (buffer == NULL)
		return (NULL);

	token = strtok(line_cp, delim);

	for (i = 0; token != NULL; i++)
	{
		buffer[i] = _strdup(token);
		token = strtok(NULL, delim);
	}

	buffer[i] = NULL;
	free(line_cp);
	return (buffer);
}

/**
 * count_token - Counts tokens in the passed string.
 * @cmd_line: String that is separated by an specified delimeter
 * @delim: The desired delimeter to separate tokens.
 * Return: Upon success the total count of the tokens. Otherwise -1.
 */

int count_token(char *cmd_line, const char *delim)
{
	char *str, *token;
	int i;

	str = _strdup(cmd_line);

	if (str == NULL)
		return (-1);
	token = strtok(str, delim);

	for (i = 0; token != NULL; i++)
		token = strtok(NULL, delim);

	free(str);
	return (i);
}

/**
 * path_token - makes paths as an array of strings contining the path dir
 * @index: Index of the path in the environment variables
 * @str: string to separate
 * Return: array of pointer to strings
 */

char **path_token(int index, char *str)
{
	int len, token_len;
	const char *delim = ":\n";
	char **path_tokens, *e_var;

	len = _strlen(str);
	token_len = 0;
	/*Moving the pointer len of str plus = sign*/
	e_var = environ[index] + (len + 1);
	path_tokens = get_token(e_var, delim, token_len);

	if (path_tokens == NULL)
		return (NULL);

	return (path_tokens);
}
