#ifndef DECK_H
#define DECK_H

#include <stdio.h>
#include <stdlib.h>

/**
 * enum kind_e - Enumeration of card suits
 *
 * @SPADE: Spade suit (0)
 * @HEART: Heart suit (1)
 * @CLUB: Club suit (2)
 * @DIAMOND: Diamond suit (3)
 *
 * Represents the suit (kind) of a card in increasing order of priority.
 * The sorting order is: Spades, Hearts, Clubs, then Diamonds.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

/**
 * struct card_s - Playing card
 *
 * @value: Value of the card
 * From "Ace" to "King"
 * @kind: Kind of the card
 */
typedef struct card_s
{
	const char *value;
	const kind_t kind;
} card_t;

/**
 * struct deck_node_s - Deck of card
 *
 * @card: Pointer to the card of the node
 * @prev: Pointer to the previous node of the list
 * @next: Pointer to the next node of the list
 */
typedef struct deck_node_s
{
	const card_t *card;
	struct deck_node_s *prev;
	struct deck_node_s *next;
} deck_node_t;


int _strcmp(const char *s1, const char *s2);
int compare_cards(const card_t *card_1, const card_t *card_2);
void insertion_sort_deck(deck_node_t **deck);
void sort_deck(deck_node_t **deck);




#endif
