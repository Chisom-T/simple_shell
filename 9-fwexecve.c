#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

/**
 * main - shell for fork + wait + execve
 * Return: int
 */

int main(void)
{
	int pid1, pid2, pid3, status;
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};

	pid1 = fork();
	pid2 = fork();
	pid3 = fork();

	if (pid1 == 0)
	{
		if (pid2 == 0)
		{
			if (pid3 == 0)
			{
				execve(argv[0], argv, NULL);
				sleep(2);
			}
			else
			{
				execve(argv[0], argv, NULL);
				sleep(2);
			}
		}
		else
		{
			if (pid3 == 0)
			{
				execve(argv[0], argv, NULL);
				sleep(2);
			}
			else
				wait(&status);
		}
	}
	else
	{
		if (pid2 == 0)
		{
			if (pid3 == 0)
			{
				execve(argv[0], argv, NULL);
				sleep(2);
			}
			else
			{
				wait(&status);
				sleep(2);
			}
		}
		else
		{
			if (pid3 == 0)
			{
				execve(argv[0], argv, NULL);
				sleep(2);
			}
			else
			{
				wait(&status);
			}

		}
	}
	while (wait(NULL) != -1 || errno != ECHILD)
		;

	return (0);
}
