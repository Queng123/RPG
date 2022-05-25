/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** current_item
*/

#include "rpg.h"

void display_key_rand(game_t *game)
{
    game->boss_s->background[3]->rect.left =
    (game->boss_s->key_rand % 10) * 193;
    game->boss_s->background[3]->rect.top = (game->boss_s->key_rand / 10) * 157;
}
