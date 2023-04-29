#include <stdio.h>

/**
 * print_deck - Prints a deck of cards
 *
 * @deck: deck to be printed
 *
 */

void print_deck(const deck_node_t *deck)
{
    int x;

    x = 0;
    while (deck)
    {
        if (x > 0)
            printf(", ");
        printf("{%s, %s}", deck->card->value, deck->card->kind);
        ++x;
        deck = deck->next;
    }
    printf("\n");
}
