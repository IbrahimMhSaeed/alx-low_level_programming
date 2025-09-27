#include <stdio.h>

/**
 * _puts_recursion - print string with recursion
 *
 *@s: string to be printed
 *
 * Return: None
 */

int factorial (int n)
{
	if (n < 0)
		return (-1);
	if (n == 0)
		return (1);
	else
		return (n * factorial(n - 1));
}
