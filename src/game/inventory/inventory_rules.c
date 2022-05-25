/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** inventory_rules
*/

#include "rpg.h"

void reset_inventory_item(game_t *game)
{
    inventory_t *inv = game->player->inventory;

    for (int i = 0; i < 12; i++) {
        if (inv->items[i]->nb_item <= 0) {
            inv->items[i]->enum_item_e = NONE;
        }
    }
    if (game->player->item_hand->nb_item <= 0) {
        game->player->item_hand->enum_item_e = HAND;
    }
}
