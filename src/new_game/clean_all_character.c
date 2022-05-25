/*
** EPITECH PROJECT, 2022
** clean_all_character.c
** File description:
** function that clean all character create in new_game
*/

#include "rpg.h"

int clean_all_character(game_t *game)
{
    for (int a = 0; a != 19; a++) {
        sfSprite_destroy(game->new_game->character[a].spr);
    }
    return (0);
}
