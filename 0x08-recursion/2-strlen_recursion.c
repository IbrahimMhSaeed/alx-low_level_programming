#include "main.h"

/**
 * _strlen_recursion - prints
 * @s: string to print
 * Return: length;
 */

int _strlen_recursion(char *s)
{
	int count = 0;

	if (*s > '\0')
		count += _strlen_recursion(s + 1) + 1;

	return (count);

}
