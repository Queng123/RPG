/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** current_item
*/

#include "rpg.h"

void display_systeme_qte(game_t *game)
{
    sfSprite_setTextureRect(game->boss_s->background[3]->sprite,
    game->boss_s->background[3]->rect);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[3]->sprite, NULL);
}
