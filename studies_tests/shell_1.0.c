#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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

	if (write(STDOUT_FILENO, "#cisfun$ ", 9) == -1)
		perror("write");

	while (getline(&line, &len, stdin) != EOF)
	{
		argv = _strtok(line, " \n");

		if (argv[0] == NULL)
		{
			if (write(STDOUT_FILENO, "#cisfun$ ", 9) == -1)
				perror("write");
			getline(&line, &len, stdin);
		}
		pid = _fork();
		if (pid == 0)
		{
			_execve(argv[0], argv, env);
		}
		else
		{
			wait(&status);
			if (write(STDOUT_FILENO, "#cisfun$ ", 9) == -1)
			perror("write");
		}
	}

	free(line);

	return (0);
}
