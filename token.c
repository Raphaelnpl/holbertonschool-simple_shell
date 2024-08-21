#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - Splits a string into an array of words (tokens).
 * @str: The string to split.
 *
 * Return: An array of pointers to the tokens, or NULL on failure.
 */
char **split_string(char *str)
{
	char **result = NULL;
	char *current_word;
	size_t idx = 0;
	size_t token_capacity = 16;

	if (!str)
		return (NULL);

	result = malloc(token_capacity * sizeof(char *));
	if (!result)
	{
		perror("Unable to allocate memory");
		return (NULL);
	}

	current_word = strtok(str, " \n\t\r\a");
	while (current_word)
	{
		result[idx] = current_word;
		idx++;

		if (idx >= token_capacity)
		{
			token_capacity *= 2;
			result = realloc(result, token_capacity * sizeof(char *));
			if (!result)
			{
				perror("Memory reallocation failed");
				return (NULL);
			}
		}

		current_word = strtok(NULL, " \n\t\r\a");
	}
	result[idx] = NULL;

	return (result);
}

/**
 * dealloc_tokens - Frees the memory allocated for the token array.
 * @tokens: The array of tokens to free.
 */
void dealloc_tokens(char **tokens)
{
	if (tokens)
		free(tokens);
}
