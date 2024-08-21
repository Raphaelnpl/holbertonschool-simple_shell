#include "main.h"
/**
 * main - Entry point
 * @argc: Argument count
 * @argv: Argument vector
 *
 * Return: 0 on success, other values on failure
 */
int main(int argc, char **argv)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	char *args[64];
	int i;

	(void)argc;
	(void)argv;

	while (1)
	{
		printf("($) ");
		nread = getline(&line, &len, stdin);
		if (nread == -1)
		{
			free(line);
			break;
		}

		i = 0;
		args[i] = strtok(line, " \n");
		while (args[i] != NULL && i < MAX_ARGS - 1)
		{
			i++;
			args[i] = strtok(NULL, " \n");
		}
		args[i] = NULL;

		if (args[0] == NULL)
		{
			continue;
		}
		if (strcmp(args[0], "env") == 0)
		{
			print_env(environ);
			continue;
		}
		execute(args);
	}
	return (0);
}
