#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_SIZE 1024
#define MAX_ARG_SIZE 100

void parse_input(char *input, char **args) {
	for (int i = 0; i < MAX_ARG_SIZE; i++) {
		args[i] = strsep(&input, " \n");
		if (args[i] == NULL)
			break;
		if (strlen(args[i]) == 0)
			i--;
	}
}

void execute_command(char **args) {
	pid_t pid = fork();

	if (pid < 0) {
		perror("Fork failed");
	} else if (pid == 0) {
		if (execvp(args[0], args) == -1) {
			perror("Execution failed");
		}
		exit(EXIT_FAILURE);
	} else 
	{
		wait(NULL);
	}
}

int main() {
	char input[MAX_INPUT_SIZE];
	char *args[MAX_ARG_SIZE];

	while (1) {
		printf("shell> ");
		fgets(input, MAX_INPUT_SIZE, stdin);

		parse_input(input, args);

		if (strcmp(args[0], "exit") == 0) {
			break;
		}

		execute_command(args);
	}

	return 0;
}
