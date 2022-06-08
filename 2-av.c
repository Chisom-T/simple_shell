#include <stdio.h>
#include <stdlib.h>

/**
 * main - print all cli arguments without arg count
 * @ac: argument count
 * @av: pointer to argumnet array
 * Return: int 0 when successful
 */

int main(__attribute__ ((unused))int ac, char **av)
{
	int i;

	if (av[1] == NULL)
		return (1);

	/*loops throught the list of argument excluding the*/
	/*first which is the file name*/
	for (i = 1; av[i] != NULL; i++)
		printf("%s ", av[i]);
	printf("\n");
	return (0);
}
