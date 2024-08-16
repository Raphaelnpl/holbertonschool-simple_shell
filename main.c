#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

#define BUFFER_SIZE 1024

/**
 * main - Entry point of the shell program
 *
 * Return: Always 0 (success), or exit status if an error occurs
 */
int main(void)
{
	char *buffer = NULL;
	size_t bufsize = 0;
	ssize_t getline_status;
	char *args[BUFFER_SIZE];
	int status;
	pid_t pid;

	while (1)
	{
		printf("($) ");
		getline_status = getline(&buffer, &bufsize, stdin);

		if (getline_status == -1)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		buffer[strcspn(buffer, "\n")] = '\0';

		if (strcmp(buffer, "exit") == 0)
		{
			free(buffer);
			exit(EXIT_SUCCESS);
		}

		if (strcmp(buffer, "env") == 0)
		{
			print_env();
			continue;
		}

		pid = fork();

		if (pid == -1)
		{
			perror("fork");
			free(buffer);
			exit(EXIT_FAILURE);
		}
		else if (pid == 0)
		{
			tokenize(buffer, args);

			if (execve(args[0], args, environ) == -1)
			{
				perror("./hsh");
			}
			exit(EXIT_FAILURE);
		}
		else
		{
			wait(&status);
		}
	}

	free(buffer);
	return (0);
}
