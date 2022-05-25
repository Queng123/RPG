/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** inventory_interaction
*/

#include "rpg.h"

int is_mouse_in_rect(sfVector2i mpos, sfIntRect rect);
void switch_item(inventory_t *inv, player_t *player, int idx, int i);

static const sfIntRect pos[14] = {{1368, 851, 72, 72}, {1446, 851, 72, 72},
{1525, 851, 72, 72}, {1602, 851, 72, 72}, {1680, 851, 72, 72},
{1760, 851, 72, 72}, {1368, 929, 72, 72}, {1446, 929, 72, 72},
{1525, 929, 72, 72}, {1602, 929, 72, 72},
{1680, 929, 72, 72}, {1760, 929 , 72, 72}, {1100, 970, 72, 72},
{1382, 735, 244, 84}};

void display_waiting(game_t *game)
{
    inventory_t *inv = game->player->inventory;
    sfSprite *sprite = inv->switch_b->sprite;
    sfVector2f origin = {inv->switch_b->rect.width / 2,
    inv->switch_b->rect.height / 2};
    sfVector2f pos = inv->switch_b->pos;
    pos.x += 32;
    pos.y += 32;

    if ((inv->is_clicked == -1)) {
        return;
    }
    sfSprite_rotate(sprite, -10);
    sfSprite_setOrigin(sprite, origin);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setScale(sprite, inv->switch_b->scale);
    sfRenderWindow_drawSprite(game->game_info->window, sprite, NULL);
}

void set_inventory_right(player_t *player, inventory_t *inv)
{
    for (int i = 0; i < 12; i++) {
        if (inv->items[i]->enum_item_e == HAND) {
            inv->items[i]->enum_item_e = NONE;
        }
    }
    if (player->item_hand->enum_item_e == NONE) {
        player->item_hand->enum_item_e = HAND;
    }
}

void select_item(inventory_t *inv, int i)
{
    inv->switch_b->pos.x = pos[i].left;
    inv->switch_b->pos.y = pos[i].top;
    inv->is_clicked *= -1;
    inv->item_idx = i;
}

void click_inventory(game_t *game, sfMouseButtonEvent mouse)
{
    inventory_t *inv = game->player->inventory;
    sfVector2i mouse_pos = {mouse.x, mouse.y};
    int cilck = inv->is_clicked;
    int idx = inv->item_idx;

    if (inv->backpack->pos.y > 500) {
        return;
    }
    for (int i = 0; i < 14; i++) {
        if (is_mouse_in_rect(mouse_pos, pos[i]) == 0 && cilck == -1) {
            select_item(inv, i);
        } else if (is_mouse_in_rect(mouse_pos, pos[i]) == 0 && cilck == 1) {
            switch_item(inv, game->player, idx, i);
        }
    }
    set_inventory_right(game->player, inv);
}
