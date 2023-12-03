#include "main.h"

/**
 * clear_bit: clear bit
 * @n: number to be cleared
 * @index: index of number
 * Return: always 0 (Success)
 */


int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index < 64)
	{
		*n -= 1 << index;
		return (1);
	}
	
	return (-1);
}
