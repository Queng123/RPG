/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** current_item
*/

#include "rpg.h"

void display_pop_art(game_t *game)
{
    if (game->boss_s->fight == false) {
        if (game->boss_s->display_pop_art == 1)
            display_ouch(game);
        if (game->boss_s->display_pop_art == 2)
            display_paf(game);
    }
}
