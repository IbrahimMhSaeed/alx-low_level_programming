#include <stdio.h>

/**
 * main - Entry point
 *
 * Description: Print all letters in lower case
 *
 * Return: Always (0) Success
 */

int main(void)
{
	char i;

	for (i = 'a'; i <= 'z'; i++)
	{
		putchar(i);
	}
	putchar('\n');

	return (0);
}
