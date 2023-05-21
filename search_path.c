#include <string.h>
#include <unistd.h>
#include "main.h"


/**
 * path_dir - prints each directory contained in the the environment
 * variable PATH, one directory per line.
 */
char *path_dir(char *program)
{
	char *path, *path_d, *dir;

	path = _getenv("PATH");
	if (path == NULL)
		return (NULL);

	dir = strtok(path, ":");
	if (dir == NULL)
		return (NULL);

	while (dir)
	{
		path_d = str_concat(dir, "/");
		program = str_concat(path_d, program);
		if (access(program, X_OK) == 0)
			break;

		dir = strtok(NULL, ":");
	}
	return (program);
}
