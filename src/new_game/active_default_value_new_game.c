/*
** EPITECH PROJECT, 2022
** active_default_value_new_game.c
** File description:
** function that init default value for clock and different variables
*/

#include "rpg.h"

int active_default_value_new_game(game_t *game)
{
    if (create_all_character(game) == 84)
        return (84);
    sfClock_restart(game->new_game->cat.clock);
    restore_default_rotation_character(game);
    game->new_game->class = 0;
    restart_default_value_game(game);
    return (0);
}
