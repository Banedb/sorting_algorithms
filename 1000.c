#include <stdlib.h>
#include <string.h>
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

/* Function to compare two cards for sorting */
int compare_cards(const void *card1, const void *card2)
{
	const card_t *c1 = *(const card_t **)card1;
	const card_t *c2 = *(const card_t **)card2;

	if (c1->kind == c2->kind)
		return _strcmp(c1->value, c2->value);

	return c1->kind - c2->kind;
}

/* Function to merge two halves of an array */
void merge(card_t **cards, size_t left, size_t mid, size_t right, card_t **temp)
{
	size_t i = left, j = mid + 1, k = left;

	while (i <= mid && j <= right)
	{
		if (compare_cards(&cards[i], &cards[j]) <= 0)
			temp[k++] = cards[i++];
		else
			temp[k++] = cards[j++];
	}

	while (i <= mid)
		temp[k++] = cards[i++];

	while (j <= right)
		temp[k++] = cards[j++];

	for (i = left; i <= right; i++)
		cards[i] = temp[i];
}

/* Function to perform the merge sort */
void merge_sort(card_t **cards, size_t left, size_t right, card_t **temp)
{
	if (left < right)
	{
		size_t mid = left + (right - left) / 2;
		merge_sort(cards, left, mid, temp);
		merge_sort(cards, mid + 1, right, temp);
		merge(cards, left, mid, right, temp);
	}
}

/* Function to sort a deck of cards */
void sort_deck(deck_node_t **deck)
{
	size_t deck_size = 0, i;
	deck_node_t *node = *deck;
	card_t *cards[52], **temp;

	/* Store the cards in an array */
	while (node != NULL)
	{
		cards[deck_size] = (card_t *)node->card;
		node = node->next;
		deck_size++;
	}

	/* Temporary array for merging */
	temp = malloc(deck_size * sizeof(card_t *));
	if (temp == NULL)
	{
		/* Handle memory allocation failure if needed */
		return;
	}

	/* Sort the array of cards using Merge Sort */
	merge_sort(cards, 0, deck_size - 1, temp);

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
