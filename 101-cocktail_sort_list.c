#include "sort.h"

/**
 *_swap - Swaps two nodes in a doubly linked list
 *@node1: The first node to be swapped
 *@node2: The second node to be swapped
 *@list: The list containing the nodes to be swapped
 *Return: Nothing
 */

void _swap(listint_t *node1, listint_t *node2, listint_t **list)
{
	listint_t *temp;

	if (node1->prev != NULL)
		node1->prev->next = node2;
	else *list = node2;

	if (node2->next != NULL)
		node2->next->prev = node1;

	node1->next = node2->next;
	node2->prev = node1->prev;
	node1->prev = node2;
	node2->next = node1;

	temp = node1;
	node1 = node2;
	node2 = temp;

	print_list(*list);
}

/**
 *cocktail_sort_list - Sorts a doubly linked list of integers in ascending
 *order using the Cocktail shaker sort algorithm
 *@list: The list to be sorted
 *Return: Nothing
 */

void cocktail_sort_list(listint_t **list)
{
	listint_t *current;
	int swapped = 1;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = *list;

	while (swapped == 1)
	{
		swapped = 0;

		while (current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				_swap(current, current->next, list);
				swapped = 1;
			}
			else
				current = current->next;
		}

		if (swapped == 0)
			break;

		swapped = 0;
		current = current->prev;

		while (current->prev != NULL)
		{
			if (current->n < current->prev->n)
			{
				_swap(current->prev, current, list);
				swapped = 1;
			}
			else
				current = current->prev;
		}
	}
}
