#include <stdio.h>

/**
 * main - Entry point
 * @ac: The number of arguments passed to the program
 * @av: The NULL terminated array of strings passed to the program
 * as argument.
 *
 * Return: Always 0
 */
int main(int __attribute__((unused)) ac, char *av[])
{
	int i;

	for (i = 1; av[i]; i++)
		printf("%s\n", av[i]);

	return (0);
}
