#include "main.h"

/**
 * set_bit: set bit at index
 * @n: number to be modified
 * @index: of selected bit
 * Return: always 0 (Success)
 */

int set_bit(unsigned long int *n, unsigned int index)
{
	if (index < 64)
	{
		*n += 1 << index;
		return (1);
	}
	
	return (-1);
}
