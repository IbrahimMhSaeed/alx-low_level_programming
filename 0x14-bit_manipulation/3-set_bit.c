#include "main.h"



int set_bit(unsigned long int *n, unsigned int index)
{
	if (index < 64)
	{
		*n += 1 << index;
		return (1);
	}
	
	return (-1);
}
