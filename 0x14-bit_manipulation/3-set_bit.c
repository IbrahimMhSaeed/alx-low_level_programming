#include "main.h"



int set_bit(unsigned long int *n, unsigned int index)
{
	unsigned long int i;
	if (index > 64)
		return (-1);

	i = (*n) >> index;

	if ((i & 1) == 1)
		return (-1);

	*n += (2 << (index - 1));

	return (1);

}
