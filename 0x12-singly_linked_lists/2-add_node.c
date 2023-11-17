#include <stdio.h>
#include "lists.h"
#include <string.h>

/**
 * add_node - count list element
 * @head: pointer for list header
 * @str: string to copy
 * Return: number of nodes in list
 */

list_t *add_node(list_t **head, const char *str)
{
	list_t *node = malloc(sizeof(list_t));

	if (node == NULL)
		return (NULL);

	node->next = *head;
	node->str = strdup(str);
	node->len = strlen(str);
	*head = node;

	return (*head);
}
