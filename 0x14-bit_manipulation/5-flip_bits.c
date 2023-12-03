#include "main.h"

/**
 * flip_bits: number of bits to flib to reached required number
 * @n: first number
 * @m: second number
 * Return: number of bits needed
 */

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int cmp;
	int count = 0;

	cmp = n ^ m;

	while (cmp)
	{
		if ((cmp & 1) == 1)
			count++;

		cmp = cmp >> 1;
	}
	
	return (count);
}
