#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - prints the environment using the global variable environ.
 *
 * Return: Always 0.
 */
int main(void)
{
	char **env = environ;
	int i;

	i = 0;
	while (env[i])
	{
		printf("%s\n", env[i]);
		i++;
	}
	return (0);
}
