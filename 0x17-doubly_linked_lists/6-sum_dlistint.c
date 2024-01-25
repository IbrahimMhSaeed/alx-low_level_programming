#include "lists.h"

/**
 * sum_dlistint - sum all data in dlist
 * @head: header of dlist
 * Return: return sum of int
 */

int sum_dlistint(dlistint_t *head)
{
	int sum;

	sum = 0;
	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
