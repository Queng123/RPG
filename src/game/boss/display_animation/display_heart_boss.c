/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void display_heart_boss(game_t *game)
{
    sfSprite_setTextureRect(game->boss_s->background[10]->sprite,
    game->boss_s->background[10]->rect);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[10]->sprite, NULL);
}
