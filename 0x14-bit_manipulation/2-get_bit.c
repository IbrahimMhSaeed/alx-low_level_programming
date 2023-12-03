#include "main.h"
#include <stdbool.h>

/**
 * get_bit: bit at specific index
 * @n: number to get index from
 * @index: to be searched
 * Return: bit at index
 */


int get_bit(unsigned long int n, unsigned int index)
{
	unsigned long int i;

	if (index > 64)
		return (-1);

	i = n >> index;

	return (i & 1);
}
