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
	bool flag = false;

	while (index > 0)
	{
		if (flag == true)
			return (-1);

		n = n >> 1;
		index--;

		if (n == 0)
			flag = true;

	}

	return (n & 1);
}
