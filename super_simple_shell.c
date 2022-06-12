#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void)
{
	int i, j;
        char *token, *buffer, **argv;
        const char s[2] = " ";
        size_t len = 1024;

        buffer = malloc(sizeof(size_t) * len);
	argv = malloc(sizeof(char *) * (4 + 1));

        while (1)
        {
                printf("$ ");
                i = getline(&buffer, &len, stdin);
                if (i != EOF)
                        printf("%s", buffer);

                token = strtok(buffer, s);
		j = 0;

                while (token)
                {
                        argv[j] = strdup(token);
			j++;
                        token = strtok(NULL, s);
		}
		argv[j] = NULL;
		if (execve(argv[0], argv, NULL) == -1)
		{
			perror("Error:");
		}
        }


        return (0);

}
