#include <stdio.h>

/**
 * main - entry point
 * @argc: describe this 
 * @argv: describe this
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int i = 0;

	(void) argc;

	while (*argv != NULL)
	{
		printf("%s\n", agrv[i]);
		i++;
	}

	return (0);
}
