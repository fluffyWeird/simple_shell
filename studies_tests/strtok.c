#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * split_string - splits a string and returns an array of
 * each word of the string.
 * @str: The string to split.
 * @bytes: The number of string character.
 * @delim: The string delimiter
 *
 * Return: An array of split word.
 */
char **split_string(char *str, const char *delim)
{
	char *s, *token, **arr;
	int i, j;

	if (str == NULL)
		return (NULL);

	s = strdup(str);
	if (s == NULL)
		return (NULL);

/*	token = strtok(s, delim);
	num_token = 0;
	while (token != NULL)
	{
		num_token++;
		token = strtok(NULL, delim);
	}
*/
	i = 0;
	arr = malloc(sizeof(char *) * (i + 1));
	if (arr == NULL)
	{
		free(s);
		return (NULL);
	}

	token = strtok(s, delim);
	i = 0;
	while (token != NULL)
	{
		arr = realloc(arr, sizeof(char *) * (i + 1));
		arr[i] = strdup(token);
		if (arr[i] == NULL)
		{
			for (j = 0; j < i; j++)
			{
				free(arr[j]);
			}
			free(arr);
			free(s);
			return (NULL);
		}
		i++;
		token = strtok(NULL, delim);
	}
	arr[i] = NULL;

	free(s);

	return (arr);
}
