#include "main.h"


int square(int n, int val);

/**
 * _sqrt_recursion - prints
 * @n: string to print
 * Return: length;
 */

int _sqrt_recursion(int n)
{
	return (square(n, 1));
}

/**
 * square - prints
 * @n: val
 * @val: val
 * Return: int
 */

int square(int n, int val)
{
	if (val * val == n)
		return (val);
	else if (val * val < n)
		return (square(n, val + 1));
	else
		return (-1);

}
