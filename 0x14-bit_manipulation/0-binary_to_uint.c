#include "main.h"

bool checkNum(const char *b);

/**
 * checkNum - check the code
 * @b: string to be checked
 * Return: True (Success)
 */

bool checkNum(const char *b)
{
	if (b == NULL)
		return (false);

	while (b != NULL)
	{
		if (*b != 48 || *b != 49)
			return (false);
		b++;
	}
	
	return (true);
}

/**
 * binary_to_uint - change binary to unsigned int
 * @b: number to be changed
 * Return: unsigned int number
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int num = 0;

	if (!checkNum(b))
		return (0);

	while (b != NULL)
	{
		if (*b == '1')
		{
			num = num << 1;
			num += 1;
		}else
			num = num << 1;

		b++;
	}

	return (num);
}
