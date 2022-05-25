/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void draw_frame_zero(game_t *game)
{
    if (game->intro_s->frame_one == 0) {
        for (int i = 0; i < 2; i++) {
            sfRenderWindow_drawSprite(game->game_info->window,
            game->intro_s->background[i]->sprite, NULL);
        }
    }
}
