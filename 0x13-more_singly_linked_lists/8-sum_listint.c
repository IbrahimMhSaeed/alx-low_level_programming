#include "lists.h"

/**
 * sum_listint - print list of numbers
 * @head: pointer to head of list
 * Return: node at specified index
 */

int sum_listint(listint_t *head)
{

	int sum = 0;

	if (!head)
		return (0);

	while (head)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
