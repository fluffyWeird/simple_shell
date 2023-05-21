#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "main.h"

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
int main(void)
{
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	char **arr;

	printf("$ ");
/**	char* input_string = "Hello,how are you today?";
*	char** word_array = split_string(input_string, " ", &bytes);
    for (int i = 0; i < bytes; i++) {
        printf("%s\n", word_array[i]);
    }

    free(word_array);
*/
	read = getline(&line, &len, stdin);
	if (read == -1)
		exit(98);

	printf("%s", line);
	arr = split_string(line, " ");

	while (*arr)
	{
		printf("%s\n", *arr);
		arr++;
	}

	free(line);

	return (0);


}
