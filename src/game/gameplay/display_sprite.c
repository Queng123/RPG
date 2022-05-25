/*
** EPITECH PROJECT, 2022
** physique_engine
** File description:
** player
*/

#include "gameplay.h"

void display_sprite(game_t *game_s, sfSprite *sprite)
{
    sfRenderWindow_drawSprite(game_s->game_info->window, sprite, NULL);
}
