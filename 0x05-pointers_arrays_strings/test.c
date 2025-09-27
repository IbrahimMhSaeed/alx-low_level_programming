#include "main.h"

/**
 * reset_to_98 - reset the variable value to 98
 * @n: variable to be changed
 * Return: None
 */

void print_rev(char *s)
{
	int i;
	
	i = _strlen(s);

	while (i >= 0)
	{
		_putchar(s[i]);
		i--;
	}
	_putchar('\n');
}
