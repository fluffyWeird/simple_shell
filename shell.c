#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - simple shell.
 *
 * Description: First version of super simple shell that can run commands
 * with their full path.
 *
 * Return: Always 0.
 */
int main(void)
{
	char **env = environ, **argv, *line = NULL, *full_path, *argv_zero;
	char *exit_command = "exit";
	size_t len = 0;
	int status;
	pid_t pid;

	while (1)
	{
		_isatty();
		if (getline(&line, &len, stdin) == EOF)
			break;
		argv = _strtok(line, " \n");
		if (argv == NULL)
		{
			perror("strtok");
			exit(EXIT_FAILURE);
		}
		if (argv[0] == NULL)
		{
			free(argv);
			continue;
		}
		argv_zero = argv[0];
		if (argv_zero == exit_command)
		{
			_free(argv);
			exit(EXIT_SUCCESS);
		}
		argv_zero = argv[0];
		full_path = path_dir(argv_zero);
		if (full_path != NULL)
		{
			argv[0] = _strdup(full_path);
			free(argv_zero);
		}
		else
		{
			_free(argv);
			free(full_path);
			continue;
		}
		pid = _fork();
		if (pid == 0)
		{
			_execve(argv[0], argv, env);
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(&status);
		}
		free(full_path);
		_free(argv);
	}
	free(line);
	return (0);
}
