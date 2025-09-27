#include <stdio.h>

/**
 * main - entry point
 * @argc: describe this
 * @argv: describe this
 * Return: 0 (success)
 */

int main(int argc, char *argv[])
{
	int i;

	for (i = 0; i < argc; i++)
		printf("%s\n", argv[i]);

	return (0);
}
