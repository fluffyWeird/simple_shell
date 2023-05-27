#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"


/**
 * path_dir - searches for command directory.
 * @program: The name of the command to be executed
 *
 * Return: A pointer to the found commamd or NULL if otherwise
 */
char *path_dir(char *program)
{
	struct stat st;
	char *path, *path_copy, *path_d, *dir, *command, *full_path;

	if (program == NULL)
		return (NULL);
	command = _strdup(program);
	if (command == NULL)
		return (NULL);
	if (stat(command, &st) == 0)
	{
		return (command);
	}
	path = _getenv("PATH");
	path_copy = _strdup(path);
	if (path == NULL || path_copy == NULL)
	{
		free(command);
		return (NULL);
	}

	dir = strtok(path_copy, ":");
	if (dir == NULL)
	{
		free(command);
		free(path_copy);
		return (NULL);
	}

	while (dir != NULL)
	{
		path_d = str_concat(dir, "/");
		program = str_concat(path_d, command);
		if (access(program, X_OK) == 0)
		{
			full_path = _strdup(program);
			free(command);
			free(path_copy);
			free(path_d);
			free(program);
			return (full_path);
		}
		free(path_d);
		free(program);
		dir = strtok(NULL, ":");
	}
	write(STDERR_FILENO, "./hsh: 1: ", 10);
	write(STDERR_FILENO, command, _strlen(command));
	write(STDERR_FILENO, ": not found\n", 12);
	free(command);
	free(path_copy);
	return (NULL);
}
