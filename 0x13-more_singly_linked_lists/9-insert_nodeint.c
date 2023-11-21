#include "lists.h"

/**
 * insert_node_at_index - print list of numbers
 * @head: pointer to head of list
 * @idx: index
 * @n: integer to be inserted
 * Return: node at specified index
 */

listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *node = malloc(sizeof(listint_t));
	listint_t *temp = *head;
	unsigned int count = 0;

	if (!node)
		return (NULL);

	node->next = NULL;
	node->n = n;

	if (idx == 0)
	{
		node->next = *head;
		*head = node;
		return (*head);
	}

	while (temp)
	{
		if (count == (idx - 1))
		{
			node->next = temp->next;
			temp->next = node;
			return (node);
		}

		count++;
		temp = temp->next;
	}

	return (NULL);
}
