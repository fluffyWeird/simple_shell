#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>
#include "main.h"

/**
 * main - executes the command ls -l /tmp in 5 different child processes.
 *
 * Description: executes the command ls -l /tmp in 5 different child processes
 * Each child should be created by the same process (the father).
 * Wait for a child to exit before creating a new child.
 *
 * Return: Always 0.
 */
int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/tmp", NULL};
	char *env[] = {NULL};
	pid_t pid;
	int status;

	pid = _fork();
	if (pid == 0)
	{
		_execve(argv[0], argv, env);
	}
	else
	{
		wait(&status);
		pid = _fork();
		if (pid == 0)
		{
			_execve(argv[0], argv, env);
		}
		else
		{
			wait(&status);
			printf("Coming back\n");
		}
	}
	return (0);
}
