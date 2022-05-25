/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** controls
*/

#include "rpg.h"

void choose_controls(game_t *game)
{
    int is_printable = 0;

    sfSprite_setTextureRect(game->menu->background[9]->sprite,
    game->menu->background[9]->rect);
    display_bg(game->menu->background[9], game->game_info->window);
    display_bg(game->menu->background[10], game->game_info->window);
    for (int i = 33; i != 42; i++) {
        sfSprite_setTextureRect(game->menu->buttons[i]->sprite->sprite,
        game->menu->buttons[i]->sprite->rect);
        display_button(game->menu->buttons[i], game->game_info->window);
        if (game->menu->buttons[i]->status == 1)
            is_printable = 1;
    }
    if (is_printable == 1)
        display_button(game->menu->buttons[42], game->game_info->window);
}
