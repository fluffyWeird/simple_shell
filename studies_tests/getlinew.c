#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * main - Entry point
 * @ac: The number of arguments passed to the program.
 * @av: The array of arguments passed to the program.
 *
 * Description: Prints "$ " and wait for the user to enter a command,
 * prints it on the next line.
 *
 * Return: Always 0.
 */
int main(int ac, char *av[])
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;

	printf("$ ");
	read = getline(&line, &len, stdin);
	if (read == -1)
		exit(98);

	while (read != EOF)
	{
		printf("%s$ ", line);
		/* printf("$ "); */
		read = getline(&line, &len, stdin);
	}

	free(line);
	return (0);

}
