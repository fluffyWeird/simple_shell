#include <unistd.h>

/**
 * main - Tests whether a file discriptor refers to  a terminal
 *
 * Return: 1 if fd is reffering to a terminal, 0 if otherwise
 */
int main(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(STDOUT_FILENO, "Input is connected to a terminal.\n", 34);
	}
	else
	{
		write(STDOUT_FILENO, "Input is not connected to a terminal.\n", 38);
	}

	if (isatty(STDOUT_FILENO))
	{
		write(STDOUT_FILENO, "Output is connected to a terminal.\n", 35);
	}
	else
	{
		write(STDOUT_FILENO, "Output is not connected to a terminal.\n", 39);
	}

	return (0);
}

