#include <stdlib.h>
#include <stdio.h>
#include "main.h"

/**
 * main - prints the address of env and environ
 * @ac: The number of arguments passed to the program.
 * @av: An array of arguments passed to the program.
 * @env: An array of environmental variables.
 *
 * Description: prints the address of env (the third parameter of the main
 *		function) and environ (the global variable).
 *		Are they they same? Does this make sense?
 *
 * Return: Always 0;
 */
int main(int __attribute__((unused))ac, char __attribute__((unused))**av, char **env)
{
	char **envi;

/**
 *	char ***env_ptr = &env;
 *	char ***envi_ptr = &envi;
 */
	envi = environ;
	printf("env: %p\n", (void *)&env);
	printf("envi: %p\n", (void *)&envi);
	return (0);

}
