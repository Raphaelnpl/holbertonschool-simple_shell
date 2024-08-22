#include "main.h"
/**
 * main - Entry point
 *
 * Return: 0 on success, other values on failure
 */
int main(void)
{
	char *command = NULL, *args[MAX_ARGS], *token;
	size_t command_size = 0;
	ssize_t bytes_read;
	int should_run = 1, i;

	signal(SIGINT, handle_sigint);
	while (should_run)
	{
		if (isatty(STDIN_FILENO))
		{
			printf("\033[32m@%s\033[0m ➜ \033[36m%s\033[0m $ ",
					_getenv("USER"), _getenv("PWD"));
			fflush(stdout);
		}
		bytes_read = getline(&command, &command_size, stdin);
		if (bytes_read == -1)
			break;
		if (command[0] == '\n' || command[0] == '\0')
			continue;
		command[strlen(command) - 1] = '\0';
		if (strcmp(command, "exit") == 0)
		{
			should_run = 0;
			continue;
		}
		if (strcmp(command, "env") == 0)
		{
			print_env(environ);
			continue;
		}
		for (i = 0, token = strtok(command, " "); token != NULL && i < MAX_ARGS - 1;
			i++, token = strtok(NULL, " "))
		{
			args[i] = token;
		}
		args[i] = NULL;
		execute(args);
	}
	free(command);
	return (0);
}
