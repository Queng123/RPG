/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** inventory_transactions
*/

#include "rpg.h"
#include "player.h"

int add_item(item_t * item, int nb_to_add)
{
    if (item == NULL) {
        return (1);
    }
    if (item->enum_item_e != AK47 && item->enum_item_e != BAT) {
        item->nb_item += nb_to_add;
        return (0);
    }
    return (1);
}

int try_find_empty_slot(game_t *game, enum_item_t item, int nb_item)
{
    item_t *item_s = get_specific_item(game, NONE);

    if (item_s != NULL) {
        item_s->enum_item_e = item;
        item_s->nb_item = nb_item;
        return (0);
    }
    return (1);
}

int try_add_item(game_t *game, enum_item_t item_to_add, int nb_item)
{
    item_t *item_s = get_specific_item(game, item_to_add);

    if (add_item(item_s, nb_item) != 0) {
        if (try_find_empty_slot(game, item_to_add, nb_item) == 0) {
            return (0);
        }
        return (1);
    }
    return (0);
}
