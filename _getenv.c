#include <stdio.h>
#include <string.h>
#include "main.h"

/**
 * _getenv - gets an environment variable.
 * @name: The name of the varoable to get.
 *
 * Return: A pointer to the corresponding value string
 *	or NULL if there is no match.
 */
char *_getenv(const char *name)
{
	char **env = environ;
	unsigned int len;

	if (name == NULL)
		return (NULL);

	for (len = 0; name[len]; len++)
		;
	for (; *env; env++)
	{
		if (_strstr(*env, name) == *env && (*env)[len] == '=')
		{
			return (&(*env)[len + 1]);
		}
	}
	return (NULL);
}
