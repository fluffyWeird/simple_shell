#include <string.h>
#include <stdio.h>
#include "main.h"


/**
 * path_dir - prints each directory contained in the the environment
 * variable PATH, one directory per line.
 */
void path_dir(void)
{
	char *path, *dir;

	path = _getenv("PATH");
	if (path == NULL)
		return;

	dir = strtok(path, ":");
	if (dir == NULL)
		return;

	while (dir)
	{
		printf("%s\n", dir);

		dir = strtok(NULL, ":");
	}
}
