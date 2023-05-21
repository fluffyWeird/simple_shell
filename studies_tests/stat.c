#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>

/**
 * main - looks for files in the current PATH.
 * @argc: The number of arguments passed to the program
 * @argv: An array of arguments passed to the program.
 *
 * Return: Always 0.
 */
int main(int argc, char **argv)
{
	int i;
	struct stat st;

	if (argc < 2)
	{
		printf("Usage: %s filename ...\n", argv[0]);
		return (0);
	}

	i = 1;
	while (argv[i])
	{
		printf("%s:", argv[i]);
		if (stat(argv[i], &st) == 0)
		{
			printf(" FOUND\n");
		}
		else
		{
			printf(" Not Found\n");
		}
		i++;
	}

	return (0);
}
