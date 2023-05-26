#include <stdio.h>
#include <unistd.h>
#include "main.h"

/**
 *  _isatty - est whether a file descriptor refers to a terminal
 */
void _isatty(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "$ ", 2);
		fflush(stdout);
	}
}
