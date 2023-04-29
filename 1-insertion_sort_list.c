#include "sort.h"

/**
 *insertion_sort_list - Sorts a doubly linked list of integers in ascending
 *order using the Insertion sort algorithm
 *@list: The list to be sorted
 *Return: Nothing
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	next = (*list)->next;

	while (next != NULL)
	{
		while (next->prev != NULL && next->n < next->prev->n)
		{
			next->prev->next = next->next;
			if (next->next != NULL)
				next->next->prev = next->prev;
			next->next = next->prev;
			next->prev = next->prev->prev;
			next->next->prev = next;
			if (next->prev == NULL)
				*list = next;
			else
				next->prev->next = next;
			print_list(*list);
		}

		next = next->next;
	}
}
