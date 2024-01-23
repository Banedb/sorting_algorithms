#include "sort.h"

/**
 * swap_nodes - Swaps two nodes in a doubly linked list
 * @list: Pointer to the head of the list
 * @node: ptr to node to be swapped
 */
void swap_nodes(listint_t **list, listint_t **node)
{
	listint_t *one, *two, *three, *four;

	one = (*node)->prev;
	two = *node;
	three = (*node)->next;
	four = (*node)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*node = three;
}

/**
 * cocktail_sort_list - Sorts a doubly linked list of integers
 * using the Cocktail Shaker Sort
 *
 * @list: Pointer to the head of the list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *current = *list;
	int sorted = 0;

	if (!list || !*list || !(*list)->next)
		return;
	while (!sorted)
	{
		sorted = 1;
		while (current->next)
		{
			if (current->n > current->next->n)
			{
				sorted = 0;
				swap_nodes(list, &current);
				print_list(*list);
			}
			else
				current = current->next;
		}
		if (sorted)
			break;
		current = current->prev;
		while (current->prev)
		{
			if (current->n < current->prev->n)
			{
				sorted = 0;
				current = current->prev;
				swap_nodes(list, &current);
				print_list(*list);
			}
			else
				current = current->prev;
		}
	}
}
