#include "shell.h"

/**
 * print_environ - 'prints environment variable'
 * Return: Always 0 (Success)
 */

void print_environ(void)
{
	char **env = environ;

	while (*env != NULL)
	{
		printf("%s\n", *env);
		env++;
	}
}
