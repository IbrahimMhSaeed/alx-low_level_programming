#include "lists.h"

/**
 * delete_nodeint_at_index - print list of numbers
 * @head: pointer to head of list
 * @index: index
 * Return: node at specified index
 */

int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *temp = *head;
	listint_t *del;
	unsigned int count = 0;

	if (index == 0)
	{
		*head = (*head)->next;
		free(temp);
		return (1);
	}

	while (temp)
	{
		if (count == (index - 1))
		{
			del = temp->next;
			
			if (!del)
				return (-1);


			temp->next = del->next;
			free(del);
			return (1);
		}

		count++;
		temp = temp->next;
	}

	return (-1);
}
