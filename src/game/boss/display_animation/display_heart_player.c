/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void display_heart_player(game_t *game)
{
    sfSprite_setTextureRect(game->boss_s->background[9]->sprite,
    game->boss_s->background[9]->rect);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[9]->sprite, NULL);
}
