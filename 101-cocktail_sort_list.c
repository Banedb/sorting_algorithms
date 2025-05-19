#include "sort.h"

/**
 * swap_nodes - swap nodes of a doubly_linked list
 * @list: pointer to a doubly_linked list
 * @current: node to end up on the right
 * @temp: node to end up on the left
 */
void swap_nodes(listint_t **list, listint_t *current, listint_t *temp)
{
	current->next = temp->next;
	if (current->next)
		current->next->prev = current;
	temp->next = current;
	temp->prev = current->prev;
	current->prev = temp;
	if (temp->prev)
		temp->prev->next = temp;
	else
		*list = temp;
	print_list(*list);
}

/**
 * cocktail_sort_list - implements the cocktail sort algorithm
 * @list: pointer to a doubly_linked list
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped = 1;
	listint_t *current, *temp, *start, *end = NULL;

	if (!list || !*list || !(*list)->next)
		return;

	start = *list;
	while (swapped)
	{
		swapped = 0;
		current = start;
		while (current->next != end)
		{
			if (current->n > current->next->n)
			{
				temp = current->next;
				swap_nodes(list, current, temp);
				swapped = 1;
			}
			else
				current = current->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		end = current;
		current = current->prev;
		while (current->prev && current != start)
		{
			if (current->n < current->prev->n)
			{
				temp = current->prev;
				swap_nodes(list, temp, current);
				swapped = 1;
			}
			else
				current = current->prev;
		}
		start = current->next;
	}
}
