#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * _execve - execute a program.
 * @pathname: The location of the program
 * @argv: An array of arguments.
 * @env: An array of env. variable.
 */
void _execve(const char *pathname, char *const argv[], char *const env[])
{
	if (execve(pathname, argv, env) == -1)
	{
		perror("./shell");
		exit(EXIT_FAILURE);
	}
}
