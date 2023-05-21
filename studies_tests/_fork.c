#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>

/**
 * _fork - creates a child process
 *
 * Return: 0 for the child process and child pid for the father
 */
int _fork(void)
{
	pid_t pid;

	pid = fork();
	if (pid == -1)
	{
		perror("fork");
		return (1);
	}

	return (pid);
}
