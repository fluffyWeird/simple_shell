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
	char **env = environ, **argv;
	char *line = NULL;
	size_t len = 0;
	int status;
	pid_t pid;
	struct stat st;

	while (1)
	{
		if (write(STDOUT_FILENO, "#cisfun$ ", 9) == -1)
			perror("write");
		if (getline(&line, &len, stdin) == EOF)
			break;

		argv = _strtok(line, " \n");

		if (argv[0] == NULL)
		{
			continue;
		}
		if ((stat(argv[0], &st) == 0) || (argv[0] = path_dir(argv[0])) != NULL)
		{
			pid = _fork();
			if (pid == 0)
			{
				_execve(argv[0], argv, env);
			}
			else
			{
				wait(&status);
			}
		}
		else
		{
			perror(argv[0]);
		}
	}

	free(line);

	return (0);
}
