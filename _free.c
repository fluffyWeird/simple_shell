#include <stdlib.h>

/**
 * _free - free arrays' allocated memory
 * @argv: The allocated array
 */
void _free(char **argv)
{
	unsigned int j;

	for (j = 0; argv[j] != NULL; j++)
		free(argv[j]);
	free(argv);
}
