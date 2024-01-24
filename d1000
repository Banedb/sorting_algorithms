#include "deck.h"

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
 * compare_cards - Compare two cards for sorting
 * @card1: First card to compare
 * @card2: Second card to compare
 * Return: Negative value if card1 should be before card2,
 *         positive value if card1 should be after card2,
 *         0 if card1 and card2 have the same order
 */
int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;

	if (c1->kind == c2->kind)
		return (_strcmp(c1->value, c2->value));
	return (c1->kind - c2->kind);
}

/**
 * sort_deck - Sort a deck of cards
 * @deck: Pointer to the deck of cards
 */
void sort_deck(deck_node_t **deck)
{
	size_t deck_size = 0, i;
	deck_node_t *node = *deck;
	card_t *cards[52];

	/* Store the cards in an array */
	while (node != NULL)
	{
		cards[deck_size] = (card_t *)node->card;
		node = node->next;
		deck_size++;
	}

	/* Sort the array of cards */
	qsort(cards, deck_size, sizeof(card_t *), compare_cards);

	/* Reconstruct the sorted deck */
	*deck = malloc(sizeof(deck_node_t));
	(*deck)->prev = NULL;
	node = *deck;

	for (i = 0; i < deck_size; i++)
	{
		node->card = cards[i];
		if (i < deck_size - 1)
		{
			node->next = malloc(sizeof(deck_node_t));
			node->next->prev = node;
		}
		else
		{
			node->next = NULL;
		}
		node = node->next;
	}
}
