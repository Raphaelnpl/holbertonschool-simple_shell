#include "main.h"

/**
 * print_env - Entry point.
 * @environ: A pointer to an array of strings
 * Description: This function iterates through the environment variables
 *
 * Return: This function does not return a value.
 */
void print_env(char **environ)
{
	int i = 0;

	while (environ[i] != NULL)
	{
		printf("%s", environ[i]);
		i++;
	}
}
