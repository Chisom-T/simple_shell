#include <stdio.h>
#include <stdlib.h>

/**
 * main - print argument receptor
 * Return: int 0 when succesful
 */

int main(void)
{
	char *buffer;
	size_t bufsize = 32;

	buffer = (char *)malloc(bufsize * sizeof(char));
	if (buffer == NULL)
	{
		perror("Unable to allocate buffer");
		exit(1);
	}

	printf("$ ");
	getline(&buffer, &bufsize, stdin);
	printf("%s", buffer);

	return (0);
}
