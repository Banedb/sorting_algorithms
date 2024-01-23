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
	listint_t *p;
	int sorted = 0;

	if (!list || !*list || !(*list)->next)
		return;
	p = *list;
	while (!sorted)
	{
		sorted = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sorted = 0;
				swap_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (sorted)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sorted = 0;
				p = p->prev;
				swap_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
