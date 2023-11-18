#include "main.h"

/**
 * _puts_recursion - prints
 * @s: string to print
 * Return: NONE;
 */

void _puts_recursion(char *s)
{
	if (*s == '\0')
		return ;

	_putchar(*s);
	_puts_recursion(s + 1);

}
