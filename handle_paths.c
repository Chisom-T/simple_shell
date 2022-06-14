#include "main.h"

/**
 * search_dir - Looks through dir stored in token_path for a specific file
 * @path_tokens: pointer to array of strings for paths contained in PATH env var
 * @command: Represents a command. like ls, echo, pwd, /bin/ls etc.
 * Return: string with the upper most directory containing the command file
 */

char *search_dir(char **path_tokens, char *cmd)
{
	int i, s;
	char *cwd, *buffer;
	size_t size;
	struct stat stat_buf;

	buffer = NULL;
	size = 0;
	cwd = getcwd(buffer, size);
	if (cwd == NULL)
		return (NULL);

	if (cmd[0] == '/')
		cmd = cmd + 1;

	for (i = 0; path_tokens[i] != NULL; i++)
	{
		s = chdir(path_tokens[i]);
		if (s == -1)
		{
			perror("ERROR!");
			return (NULL);
		}
		s = stat(cmd, &stat_buf);
		if (s == 0)
		{
			chdir(cwd);
			free(cwd);
			return (path_tokens[i]);
		}
	}

	chdir(cwd);
	free(cwd);
	return (NULL);
}

/**
 * build_path - Combines two strings one for path dir and other for command file
 * @dir: Represents a directory in the path
 * @cmd: Represents a file in a directory of the path
 * Return: string representing the full path of a command
 */

char *build_path(char *dir, char *cmd)
{
	int i, j, dir_len, cmd_len, len;
	char *path;

	if (dir == NULL || cmd == NULL)
		return (NULL);

	dir_len = _strlen(dir) + 1;
	cmd_len = _strlen(cmd) + 1;
	len = dir_len + cmd_len;

	path = malloc(sizeof(char) * len);
	if (path == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
	{
		for (j = 0; dir[j] != '\0'; j++, i++)
			path[i] = dir[j];
		path[i] = '/';
		i++;

		for (j = 0; cmd[j] != '\0'; j++, i++)
			path[i] = cmd[j];
	}
	path[--i] = '\0';
	return (path);
}

/**
 * gets_path - functions that will be able to find the full path of a program
 * @cmd: Represents a command. eg ls, echo, pwd, etc.
 * Return: string with the full path of the program.
 */

char *gets_path(char *cmd)
{
	char *str = "PATH";
	char *constructed, *dir, **path_t;
	int i;

	i = find_path(str);
	path_t = path_token(i, str);
	if (path_t == NULL)
		return (NULL);

	dir = search_dir(path_t, cmd);
	if (dir == NULL)
	{
		_free_double(path_t);
		return (NULL);
	}

	constructed = build_path(dir, cmd);
	if (constructed == NULL)
	{
		_free_double(path_t);
		return (NULL);
	}

	_free_double(path_t);

	return (constructed);
}

/**
 * find_path - Finds the index of an env variable
 * @str: Env variable that needs to be found
 * Return: index of the env variable
 */

int find_path(char *str)
{
	int i, len, j;

	len = _strlen(str);
	for (i = 0; environ[i] != NULL; i++)
	{
		for (j = 0; j < len; j++)
		{
			if (environ[i][j] != str[j])
				break;
		}
		if (j == len && environ[i][j] == '=')
			return (i);
	}
	return (-1);
}
