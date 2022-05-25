/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** destroy_items
*/

#include "rpg.h"

void try_destroy_item(player_t *player, inventory_t *inv, int idx, int i)
{
    item_t *temp = NULL;

    if (i == 13 && idx <= 11) {
        temp = inv->items[idx];
        if (temp->enum_item_e == MONEY)
            return;
        temp->enum_item_e = NONE;
        temp->nb_item = 0;
    } else if (i == 13 && idx == 12) {
        player->item_hand->enum_item_e = HAND;
        player->item_hand->nb_item = 0;
    }
}

void item_hand_to_inv(player_t *player, inventory_t *inv, int i)
{
    item_t *temp = player->item_hand;

    player->item_hand = inv->items[i];
    inv->items[i] = temp;
}

void item_inv_to_hand(player_t *player, inventory_t *inv, int idx)
{
    item_t *temp = player->item_hand;

    player->item_hand = inv->items[idx];
    inv->items[idx] = temp;
}

void switch_in_inv(inventory_t *inv, int idx, int i)
{
    item_t *temp = inv->items[inv->item_idx];

    inv->items[idx] = inv->items[i];
    inv->items[i] = temp;
}

void switch_item(inventory_t *inv, player_t *player, int idx, int i)
{
    inv->is_clicked = -1;

    if (idx == i) {
        return;
    }
    if (idx == 12 && i != 13) {
        item_hand_to_inv(player, inv, i);
        return;
    } else if (i == 12) {
        item_inv_to_hand(player, inv, idx);
        return;
    }
    if (idx <= 11 && i < 12) {
        switch_in_inv(inv, idx, i);
    } else {
        try_destroy_item(player, inv, idx, i);
    }
}
