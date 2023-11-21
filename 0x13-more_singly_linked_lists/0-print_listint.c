#include "lists.h"


size_t print_listint(const listint_t *h)
{

	int count = 0;

	while (h)
	{
		count++;
		printf("%i\n", count);
		h = h->next;
	}

	return count;


}
