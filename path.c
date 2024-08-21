#include "main.h"
#include <stdio.h>
#include <string.h>

/**
 * _getenv - Retrieve the value of an environment variable.
 * @name: The name of the environment variable to retrieve.
 *
 * Return: Pointer to the value of the environment variable if found,
 *         or NULL if not found.
 */
char *_getenv(const char *name)
{
	int i;
	size_t name_len = strlen(name);

	if (name == NULL || name_len == 0)
		return (NULL);

	for (i = 0; environ[i] != NULL; i++)
	{
		if (strncmp(environ[i], name, name_len) == 0 && environ[i][name_len] == '=')
		{
			return (environ[i] + name_len + 1);
		}
	}

	return (NULL);
}
/**
 * is_path - Checks if the command contains a '/' indicating it is a path.
 * @command: The command string to check.
 *
 * Return: 1 if the command is a path, 0 if not.
 */
int is_path(char *command)
{
	if (command == NULL)
		return (0);

	if (strchr(command, '/'))
		return (1);

	return (0);
}
