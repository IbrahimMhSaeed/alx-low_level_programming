#include "main.h"

/**
 * _print_rev_recursion - prints
 * @s: string to print
 * Return: NONE;
 */

void _print_rev_recursion(char *s)
{
	if (*s == '\0')
	{
		_putchar('\n');
	} else
	{
		__print_rev_recursion(s + 1);
		_putchar(*s);
	}

}
