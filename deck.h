#ifndef DECK_H
#define DECK_H

/**
 * enum kind_e - Enumeration for different card suits
 * @SPADE: Represents the spade suit
 * @HEART: Represents the heart suit
 * @CLUB: Represents the club suit
 * @DIAMOND: Represents the diamond suit
 *
 * Description: Enumerates the possible suits for playing cards.
 */
typedef enum kind_e
{
	SPADE = 0,
	HEART,
	CLUB,
	DIAMOND
} kind_t;

#include <stdio.h>
#include <stdlib.h>
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
int find_pos(deck_node_t *node);
deck_node_t *swap_card(deck_node_t *card, deck_node_t **deck);
void sort_deck(deck_node_t **deck);


#endif /* DECK_H */
