/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** sell_interactions
*/

#include "gameplay.h"
#include "player.h"

static const sfIntRect pos[16] = {{770, 251, 170, 18}, {770, 286, 170, 17},
{770, 317 , 170, 17}, {770, 352, 170, 17}, {770, 391, 170, 17},
{770, 425, 170, 17}, {770, 465, 170, 17}, {770, 504, 170, 17},
{1090, 251, 170, 18}, {1090, 286, 170, 17},
{1090, 317 , 170, 17}, {1090, 352, 170, 17}, {1090, 391, 170, 17},
{1090, 425, 170, 17}, {1090, 465, 170, 17}, {1090, 504, 170, 17}};

static const enum_item_t tab_item[16] = {AMMO, BAT, AK47, BANDAGES,
SERRINGUE, CHOCO, CARROT, BREAD, AMMO, BAT, AK47, BANDAGES,
SERRINGUE, CHOCO, CARROT, BREAD};

static const int quantities[8] = {10, 1, 1, 1, 1, 2, 5, 5};

static const int prices[8] = {200, 40, 70, 30, 400, 10, 10, 10};

int get_slot_clicked_by_mouse(sfMouseButtonEvent mouse, int start, int end)
{
    sfVector2i mouse_pos = {mouse.x, mouse.y};

    for (int i = start; i < end; i++) {
        if (is_mouse_in_rect(mouse_pos, pos[i]) == 0) {
            return (i);
        }
    }
    return (-1);
}

int handle_buying(game_t *game, sfMouseButtonEvent mouse)
{
    item_t *item_money = get_specific_item(game, MONEY);
    int pos_slot = get_slot_clicked_by_mouse(mouse, 0, 8);
    int price = 0;

    if (item_money == NULL || pos_slot == -1)
        return (1);
    price = prices[pos_slot];
    if (item_money->nb_item < price) {
        return (-1);
    }
    if (try_add_item(game, tab_item[pos_slot], quantities[pos_slot]) == 0) {
        item_money->nb_item -= price;
        return (0);
    }
    return (-1);
}
