#include "deck.h"
#include <stdio.h>

/**
 * _strcmp -  function that compares two strings.
 * @s1: first char
 * @s2: second char
 * Return: 0.
 */

int _strcmp(const char *s1, const char *s2)
{
	int res = 0;

	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	if (s1 != s2)
		res = *s1 - *s2;

	return (res);
}
/**
 * find_pos - finds card position
 * @node: card
 * Return: the card position
 */
int find_pos(deck_node_t *node)
{
	int value;

	value = (*node).card->value[0] - '0';
	if (value < 50 || value > 57)
	{
		if (_strcmp((*node).card->value, "Ace") == 1)
			value = 1;
		else if (_strcmp((*node).card->value, "10") == 1)
			value = 10;
		else if (_strcmp((*node).card->value, "Jack") == 1)
			value = 11;
		else if (_strcmp((*node).card->value, "Queen") == 1)
			value = 12;
		else if (_strcmp((*node).card->value, "King") == 1)
			value = 13;
	}
	value += (*node).card->kind * 13;
	return (value);
}
/**
 *swap_card - swaps card
 *@card: card
 *@deck: deck of cards
 *Return: ptr to switched card
 */
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck)
{
	deck_node_t *back = card->prev, *current = card;

	back->next = current->next;
	if (current->next)
		current->next->prev = back;
	current->next = back;
	current->prev = back->prev;
	back->prev = current;
	if (current->prev)
		current->prev->next = current;
	else
		*deck = current;
	return (current);
}

/**
 * sort_deck - sort a deck you put in using
 * insertion sort algorithm
 * @deck: deck
 */
void sort_deck(deck_node_t **deck)
{
	int value_prev, value_current;
	deck_node_t *node;

	if (deck == NULL || (*deck)->next == NULL)
		return;
	node = (*deck)->next;
	while (node)
	{
		/* preparing the previous value */
		if (node->prev)
		{
			value_prev = find_pos((node->prev));
			value_current = find_pos(node);
		}
		while ((node->prev) && (value_prev > value_current))
		{
			value_prev = find_pos((node->prev));
			value_current = find_pos(node);
			node = swap_card(node, deck);

		}
		node = node->next;
	}
}
