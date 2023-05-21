#include "main.h"
#include <stddef.h>

/**
 * _strchr - locates a character in a string.
 * @s: The string to search.
 * @c: The character to locate
 *
 * Return: The first occurence of the string to a pointer or NULL of not found.
 */
char *_strchr(char *s, char c)
{
	int i;

	for (i = 0; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
		{
			return (s + i);
		}
	}
	return (NULL);
}
