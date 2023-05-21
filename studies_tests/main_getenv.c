#include <stdio.h>
#include "main.h"

/**
 * main - Entry point
 *
 * Description: Test _getenv function.
 *
 * Return: Always 0;
 */
int main(void)
{
	char *value;

	value = _getenv("PATH");

	printf("PATH: %s\n", value);

	return (0);
}
