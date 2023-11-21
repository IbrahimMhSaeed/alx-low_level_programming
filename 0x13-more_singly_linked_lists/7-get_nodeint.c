#include "lists.h"

/**
 * get_nodeint_at_index - print list of numbers
 * @head: pointer to head of list
 * @index: index of node
 * Return: node at specified index
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{

	unsigned int count = 0;

	if (!head)
		return (NULL);

	while (head)
	{
		if (count == index)
			break;

		count++;
		head = head->next;
	}

	if (count != index)
		return (NULL);

	return (head);
}
