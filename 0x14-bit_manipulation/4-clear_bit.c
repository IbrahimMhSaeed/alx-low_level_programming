#include "main.h"

/**
 * clear_bit - get bit value
 * @n: number to get bit
 * @index: index of bit to get
 * Return: always 1 (success)
 */

int clear_bit(unsigned long int *n, unsigned int index)
{

	if (index > 64 || !n)
		return (-1);

	(*n &= ~(1 << index));
	
	return (1);
}
