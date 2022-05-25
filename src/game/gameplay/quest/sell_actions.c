/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** sell_actions
*/

#include "rpg.h"
#include "player.h"

static const enum_item_t tab_item[16] = {AMMO, BAT, AK47, BANDAGES,
SERRINGUE, CHOCO, CARROT, BREAD, AMMO, BAT, AK47, BANDAGES,
SERRINGUE, CHOCO, CARROT, BREAD};

static const int quantities[8] = {10, 1, 1, 1, 1, 2, 5, 5};

static const int prices[8] = {100, 20, 30, 10, 100, 3, 2, 2};

int handle_selling(game_t *game, sfMouseButtonEvent mouse)
{
    item_t *item_money = get_specific_item(game, MONEY);
    item_t *item_remove = NULL;
    int pos_slot = get_slot_clicked_by_mouse(mouse, 8, 16) - 8;
    int price = 0;

    if (item_money == NULL || pos_slot < 0)
        return (1);
    price = prices[pos_slot];
    item_remove = get_specific_item(game, tab_item[pos_slot]);
    if (item_remove != NULL && item_remove->nb_item >= quantities[pos_slot]) {
        item_money->nb_item += price;
        item_remove->nb_item -= quantities[pos_slot];
        return (0);
    }
    return (-1);
}

void hanle_seller_interaction(game_t *game, sfMouseButtonEvent mouse)
{
    if (game->quest->is_display != 1 || mouse.button != sfMouseLeft) {
        return;
    }
    handle_selling(game, mouse);
    handle_buying(game, mouse);
}
