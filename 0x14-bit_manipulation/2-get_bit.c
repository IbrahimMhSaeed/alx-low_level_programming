#include "main.h"

/**
 * get_bit - get bit value
 * @n: number to get bit
 * @index: index of bit to get
 * Return: value of required bit
 */

int get_bit(unsigned long int n, unsigned int index)
{
	int bit;

	if (n > 64)
		return (-1);

	bit = n >> index;
	
	return (bit & 1);
}
