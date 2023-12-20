#include "main.h"

int checkNum(const char *b);

/**
 * checkNum - check the code
 * @b: string to be checked
 * Return: True (Success)
 */

int checkNum(const char *c)
{
	const char *b = c;
	if (b == NULL)
		return (0);

	while (*b != '\0')
	{
		if (*b != '1' && *b != '0')
			return (0);
		b++;
	}

	return (1);
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


	while (*b != '\0')
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
