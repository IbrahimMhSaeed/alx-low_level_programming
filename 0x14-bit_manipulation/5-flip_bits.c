#include "main.h"

/**
 * flip_bits - get bit value
 * @n: number to get bit
 * @m: index of bit to get
 * Return: number of bits needed to be fliped
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int xor;
	unsigned int sum;

	xor = n ^ m;
	sum = 0;

	while (xor)
	{
		sum += (xor & 1);
		xor = xor >> 1;
	}

	return (sum);
}
