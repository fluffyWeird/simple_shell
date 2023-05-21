#include <stdlib.h>

/**
 * str_concat - concatenates two strings.
 * @s1: First string
 * @s2: Second string
 *
 * Return: A pointer to a newly allocated space in memory which contains the
 * contents of s1, followed by the contents of s2, and null terminated.
 * if NULL is passed, treat it as an empty string. Return NULL on failure.
 */
char *str_concat(char *s1, char *s2)
{
	int i, j, s1_len, s2_len;
	int len;
	char *str;

	if (s1 == NULL)
	{
		s1 = "";
	}
	if (s2 == NULL)
	{
		s2 = "";
	}
	for (s1_len = 0; s1[s1_len] != '\0'; s1_len++)
	{
		;
	}
	for (s2_len = 0; s2[s2_len] != '\0'; s2_len++)
	{
		;
	}
	len = s1_len + s2_len + 1;
	str = malloc(sizeof(char) * len);
	if (str == NULL)
	{
		return (NULL);
	}
	for (i = 0; i < s1_len; i++)
	{
		str[i] = s1[i];
	}
	for (j = 0; j < s2_len; j++)
	{
		str[j + s1_len] = s2[j];
	}
	str[len - 1] = '\0';
	return (str);
}
