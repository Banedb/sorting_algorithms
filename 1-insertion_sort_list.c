#include "sort.h"

/**
 * insertion_sort_list - Sorts a doubly linked list in ascending
 * order using the Insertion sort algorithm
 * @list: Pointer to the head of the doubly linked list
 *
 * Return: void
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *node1, *node2;

	if (!list || !(*list))
		return;
	current = (*list)->next;
	while (current)
	{
		node1 = current;
		current = current->next;
		while (node1->prev && node1->n < node1->prev->n)
		{
			node2 = node1->prev;
			if (node1->next)
				node1->next->prev = node1->prev;
			node1->prev->next = node1->next;
			node1->prev = node2->prev;
			node1->next = node2;
			if (node2->prev)
				node2->prev->next = node1;
			else
				*list = node1;
			node2->prev = node1;
			print_list(*list);
		}
	}
}
