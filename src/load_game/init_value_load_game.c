/*
** EPITECH PROJECT, 2022
** init_value_load_game.c
** File description:
** function that initialize default value of var
*/

#include "rpg.h"

int init_value_load_game(game_t *game)
{
    game->load_game->save[0] = false;
    game->load_game->save[1] = false;
    game->load_game->save[2] = false;
    game->load_game->delete = false;
    game->load_game->load_save = -1;
    return (0);
}
