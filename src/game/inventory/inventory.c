/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** inventory
*/

#include "rpg.h"

static const sfIntRect pos[16] = {{1368, 840, 72, 72}, {1446, 840, 72, 72},
{1525, 840, 72, 72}, {1602, 840, 72, 72}, {1680, 840, 72, 72},
{1760, 840, 72, 72}, {1368, 918, 72, 72}, {1446, 918, 72, 72},
{1525, 918, 72, 72}, {1602, 918, 72, 72},
{1680, 918, 72, 72}, {1760, 918 , 72, 72}};

void update_inventory(game_t *game, int new_state)
{
    if (new_state == -1) {
        game->player->inventory->is_display = new_state;
    } else {
        game->player->inventory->is_display = new_state;
    }
}

int is_mouse_in_rect(sfVector2i mpos, sfIntRect rect)
{
    int xm = rect.left + rect.width;
    int ym = rect.top + rect.height;
    if (mpos.x > rect.left && mpos.x <= xm &&
    mpos.y > rect.top && mpos.y <= ym) {
        return (0);
    }
    return (1);
}

void display_mouse(game_t *game)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(game->game_info->window);
    sfVector2f temp = {0, 0};
    inventory_t *inv = game->player->inventory;
    sfRenderWindow *win = game->game_info->window;

    if (game->gameplay->pause->display == true)
        return;
    for (int i = 0; i < 16; i++) {
        temp.x = pos[i].left - 9;
        temp.y = pos[i].top - 9;
        if (is_mouse_in_rect(mouse_pos, pos[i]) == 0) {
            sfSprite_setPosition(inv->square->sprite, temp);
            sfRenderWindow_drawSprite(win, inv->square->sprite, NULL);
            return;
        }
    }
}

void change_value_backpack(game_t *game, inventory_t *inv)
{
    inv->backpack->pos.y +=
    (game->gameplay->tablet->tablet_clock->time.microseconds / 1000000.0f)
    * 1500;
    inv->is_clicked = -1;
}

void display_inventory(game_t *game)
{
    inventory_t *inv = game->player->inventory;
    sfRenderWindow *win = game->game_info->window;

    display_current_item_hud(game);
    if (inv->is_display == 1 && inv->backpack->pos.y > 500) {
        inv->backpack->pos.y -=
        (game->gameplay->tablet->tablet_clock->time.microseconds / 1000000.0f)
        * 1500;
        inv->is_clicked = -1;
    } else if (inv->is_display == -1 && inv->backpack->pos.y < 1080) {
        change_value_backpack(game, inv);
    }
    sfSprite_setPosition(inv->backpack->sprite, inv->backpack->pos);
    sfRenderWindow_drawSprite(win, inv->backpack->sprite, NULL);
    if (inv->is_display == 1 && inv->backpack->pos.y <= 500) {
        display_mouse(game);
        display_inventory_item(game);
        display_waiting(game);
    }
}
