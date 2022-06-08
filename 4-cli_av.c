#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * main - takes command line are and slpit
 * Return: int
 */

int main(void)
{
	int i;
	char *token, *buffer;
	const char s[2] = " ";
	size_t len = 1024;

	buffer = malloc(sizeof(size_t) * len);

	while (1)
	{
		printf("$ ");
		i = getline(&buffer, &len, stdin);
		if (i != EOF)
			printf("%s", buffer);

		token = strtok(buffer, s);

		while (token)
		{
			printf("%s\n", token);
			token = strtok(NULL, s);
		}
	}

	return (0);
}
