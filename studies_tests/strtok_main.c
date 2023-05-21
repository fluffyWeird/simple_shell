#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main(int argc, char **argv)
{
	char **arr;
	int i;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s string delimiter\n", argv[0]);
		exit(98);
	}

	arr = split_string(argv[1], argv[2]);

	for (i = 0; arr[i] != NULL; i++)
	{
		printf("%s\n", arr[i]);
	}

	return (0);
}
