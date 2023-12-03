#include "main.h"

/**
 * get_bit: bit at specific index
 * @n: number to get index from
 * @index: to be searched
 * Return: bit at index
 */


int get_bit(unsigned long int n, unsigned int index)
{
	if (index < 0 || n < 0)
		return (-1);

	while (index > 0)
	{
		n = n >> 1;
		index--;
	}

	return (n & 1);
}
