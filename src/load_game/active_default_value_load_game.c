/*
** EPITECH PROJECT, 2022
** active_default_value_load_game.c
** File description:
** function that init default value for all var in load game
*/

#include "rpg.h"

int active_default_value_load_game(game_t *game)
{
    sfClock_restart(game->new_game->cat.clock);
    restart_default_value_game(game);
    return (0);
}
