#include "main.h"

/**
 * _strcat - concatenates two strings.
 * @dest: Destination pointer where the string is added
 * @src: source string that is added
 *
 * Return: A pointer to the resulting string dest.
 */
char *_strcat(char *dest, char *src)
{
	int i, dlen;

	dlen = 0;
	for (i = 0; dest[i] != '\0'; i++)
	{
		dlen++;
	}
	for (i = 0; src[i]; i++)
	{
		dest[dlen++] = src[i];
	}

	return (dest);
}
