/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_dialog
*/

#include "rpg.h"

void display_dialog(game_t *game)
{
    if (game->quest->clock->seconds >= 3)
        game->quest->display_text = 0;
    if (game->quest->is_display == 1 && game->quest->display_text == 1)
        display_bg(game->quest->seller->bull, game->game_info->window);
    if (game->quest->display_text == 2) {
        sfSprite_setTextureRect(game->quest->mayor->bull->sprite,
        game->quest->mayor->bull->rect);
        display_bg(game->quest->mayor->bull, game->game_info->window);
    }
}
