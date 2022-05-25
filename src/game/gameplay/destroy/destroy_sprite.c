/*
** EPITECH PROJECT, 2021
** my_hunter.c
** File description:
** header
*/

#include "gameplay.h"

void destroy_sprite(game_t *game_s)
{
    sfSprite_destroy(game_s->ground);
}
