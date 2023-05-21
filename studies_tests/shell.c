#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include "main.h"

/**
 * main - super simple shell.
 *
 * Description: First version of super simple shell that can run commands
 * with their full path, without any argument.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *line = NULL, *token;
	ssize_t bytes;
	size_t len = 0;
	int status;
	pid_t pid;
	char *argv[2];
	char *env[] = {NULL};

	printf("#cisfun$ ");
	bytes = getline(&line, &len, stdin);

	while (bytes != EOF)
	{
		token = strtok(line, "\n");
		argv[0] = token;
		if (argv[0] == NULL)
			return (1);
		argv[1] = NULL;
		pid = _fork();
		if (pid == 0)
		{
			_execve(argv[0], argv, env);
		}
		else
		{
			wait(&status);
			printf("#cisfun$ ");
			bytes = getline(&line, &len, stdin);
		}
	}

	free(line);
	return (0);

}
