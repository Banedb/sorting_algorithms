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
 * get_card_position - Get the position value of a card in a deck.
 * @node: Pointer to the deck node containing the card.
 *
 * Description: calculates and returns the position value of a car
 * within a deck. The position value is determined based on the card's
 * rank and suit, and it helps in comparing and sorting cards.
 *
 * Return: The position value of the card.
 */
int get_card_position(deck_node_t *node)
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
 * swap_card - Swap a card with its previous card in a deck.
 * @card: Pointer to the card node to be swapped.
 * @deck: Pointer to the deck containing the cards.
 *
 * Description: swaps a given card with its previous card in a deck.
 * It adjusts the pointers accordingly to maintain the deck's doubly
 * linked list structure.
 *
 * Return: Pointer to the card node after the swap.
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
 * insertion_sort - Sort a deck using the insertion sort algorithm.
 * @deck: Pointer to the deck of cards to be sorted.
 *
 * Description: This function sorts a deck using the insertion sort algorithm.
 * It compares the positions of cards and rearranges them accordingly.
 */
void insertion_sort(deck_node_t **deck)
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
			value_prev = get_card_position((node->prev));
			value_current = get_card_position(node);
		}
		while ((node->prev) && (value_prev > value_current))
		{
			value_prev = get_card_position((node->prev));
			value_current = get_card_position(node);
			node = swap_card(node, deck);

		}
		node = node->next;
	}
}
/**
 * sort_deck - Sort a deck using the insertion sort algorithm.
 * @deck: Pointer to the deck of cards to be sorted.
 *
 * Description:
 * This function acts as an entry point for sorting a deck using the
 * insertion sort algorithm. It simply calls the insertion_sort
 * function.
 */
void sort_deck(deck_node_t **deck)
{
	insertion_sort(deck);
}
