#include "main.h"

/**
 * print_binary - print decimal as binary number
 * @n: number to convert
 * Return: void (nothing)
 */

void print_binary(unsigned long int n)
{
	while (n)
	{
		if (n & 1)
			_putchar('1');
		else
			_putchar('0');

		n = n >> 1;
	}
	_putchar('\n');

}
