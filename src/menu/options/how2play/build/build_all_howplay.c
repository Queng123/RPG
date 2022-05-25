/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void build_all_howtwoplay(game_t *game)
{
    build_st_one(game->howtwoplay_s, 0);
    build_st_two(game->howtwoplay_s, 1);
    build_st_three(game->howtwoplay_s, 2);
    build_st_four(game->howtwoplay_s, 3);
    build_st_five(game->howtwoplay_s, 4);
    build_st_six(game->howtwoplay_s, 5);
}
