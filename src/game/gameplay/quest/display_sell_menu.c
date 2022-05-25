/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_sell_menu
*/

#include "gameplay.h"

static const sfIntRect pos[16] = {{770, 251, 170, 18}, {770, 286, 170, 17},
{770, 317 , 170, 17}, {770, 352, 170, 17}, {770, 391, 170, 17},
{770, 425, 170, 17}, {770, 465, 170, 17}, {770, 504, 170, 17},
{1090, 251, 170, 18}, {1090, 286, 170, 17},
{1090, 317 , 170, 17}, {1090, 352, 170, 17}, {1090, 391, 170, 17},
{1090, 425, 170, 17}, {1090, 465, 170, 17}, {1090, 504, 170, 17}};

void display_pos_mouse(game_t *game)
{
    sfVector2i mouse_pos =
    sfMouse_getPositionRenderWindow(game->game_info->window);
    sfVector2f temp = {0, 0};
    sfRenderWindow *win = game->game_info->window;

    if (game->gameplay->pause->display == true)
        return;
    for (int i = 0; i < 16; i++) {
        temp.x = pos[i].left - 15;
        temp.y = pos[i].top;
        if (is_mouse_in_rect(mouse_pos, pos[i]) == 0) {
            sfSprite_setPosition(game->quest->rect->sprite, temp);
            sfRenderWindow_drawSprite(win, game->quest->rect->sprite, NULL);
            return;
        }
    }
}

void display_sell_book(game_t *game)
{
    sfVector2f pos = {725, 150};
    sfRenderWindow *win = game->game_info->window;

    if (game->quest->is_display == -1) {
        return;
    }
    sfSprite_setPosition(game->quest->sell_menu->sprite, pos);
    sfRenderWindow_drawSprite(win, game->quest->sell_menu->sprite, NULL);
    display_pos_mouse(game);
}
