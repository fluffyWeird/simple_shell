#include "main.h"

/**
 * _strlen - returns the length of a string
 * @s: string to return its length
 *
 * Return: len, as the length of the string.
 */
int _strlen(char *s)
{
	int lens, i;

	lens = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		lens++;
	}
	return (lens);
}
