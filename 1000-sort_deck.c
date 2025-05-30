#include "deck.h"

/**
 * _strcmp -  function that compares two strings.
 * @s1: first string
 * @s2: second string
 * Return: 0 (same) || diff
 */
int _strcmp(const char *s1, const char *s2)
{
	while (*s1 == *s2 && *s1 != '\0')
	{
		s1++;
		s2++;
	}
	return (*s1 - *s2);
}

/**
 * compare_cards - compares cards in deck
 * @card_1: first card
 * @card_2: second card
 *
 * Return: -1 (if less) || 1 (if more) || 0 (otherwise)
 */
int compare_cards(const card_t *card_1, const card_t *card_2)
{
	int i, val_1 = -1, val_2 = -1;
	char *values[] = {"Ace", "2", "3", "4", "5", "6", "7", "8",
			  "9", "10", "Jack", "Queen", "King"};

	if (card_1->kind < card_2->kind)
		return (-1);
	else if (card_1->kind > card_2->kind)
		return (1);

	for (i = 0; i < 13 && (val_1 == -1 || val_2 == -1); i++)
	{
		if (val_1 == -1 && !_strcmp(card_1->value, values[i]))
			val_1 = i;
		if (val_2 == -1 && !_strcmp(card_2->value, values[i]))
			val_2 = i;
	}
	if ((val_1 != -1 && val_2 != -1) && val_1 < val_2)
		return (-1);
	else if ((val_1 != -1 && val_2 != -1) && val_1 > val_2)
		return (1);
	return (0);

}

/**
 * insertion_sort_deck - uses insertion sort algorithm to sort a deck of cards
 * @deck: doubly linked deck to sort
 */
void insertion_sort_deck(deck_node_t **deck)
{
	deck_node_t *current, *temp, *next;

	current = (*deck)->next;
	while (current)
	{
		next = current->next;
		while (current->prev &&
		       compare_cards(current->card, current->prev->card) < 0)
		{
			temp = current->next;
			current->next = current->prev;
			current->next->next = temp;
			if (temp)
				temp->prev = current->next;
			current->prev = current->next->prev;
			current->next->prev = current;
			if (current->prev)
				current->prev->next = current;
			else
				*deck = current;
		}
		current = next;
	}
}

/**
 * sort_deck - sorts a deck of cards
 * @deck: deck to sort
 */
void sort_deck(deck_node_t **deck)
{
	if (!deck || !*deck || !(*deck)->next)
		return;

	insertion_sort_deck(deck);
}
