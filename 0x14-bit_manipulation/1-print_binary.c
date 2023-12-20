#include "main.h"

/**
 * print_binary - print decimal as binary number
 * @n: number to convert
 * Return: void (nothing)
 */

void print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);

	if (n & 1)
		_putchar('1');
	else
		_putchar('0');

}
