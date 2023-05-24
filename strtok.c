#include <stdlib.h>
#include <string.h>
#include "main.h"

/**
 * _strtok - splits a string and returns an array of
 * each word of the string.
 * @str: The string to split.
 * @delim: The string delimiter
 *
 * Return: An array of split word.
 */
char **_strtok(char *str, const char *delim)
{
	char *s, *token, **arr;
	unsigned int i, j;

	if (str == NULL)
		return (NULL);

	s = _strdup(str);
	if (s == NULL)
		return (NULL);

	arr = NULL;
	i = 0;
	arr = malloc(sizeof(char *) * (i + 2));
	if (arr == NULL)
	{
		free(s);
		exit(EXIT_FAILURE);
	}
	token = strtok(s, delim);
	while (token != NULL)
	{
		arr[i] = _strdup(token);
		if (arr[i] == NULL)
		{
			free(s);
			for (j = 0; j < i; j++)
			{
				free(arr[j]);
			}
			free(arr);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
		if (token != NULL)
		{
			arr = _realloc(arr, sizeof(char *) * (i + 1), sizeof(char *) * (i + 2));
		}
	}
	arr[i] = NULL;
	free(s);
	return (arr);
}
