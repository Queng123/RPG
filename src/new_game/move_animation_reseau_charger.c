/*
** EPITECH PROJECT, 2022
** move_animation_reseau_charger.c
** File description:
** function that move animation of charger and reseau in tablet
*/

#include "rpg.h"

int move_animation_reseau_charger(game_t *game)
{
    game->menu->options_clock->time =
    sfClock_getElapsedTime(game->menu->options_clock->clock);
    game->menu->options_clock->seconds +=
    game->menu->options_clock->time.microseconds / 1000000.0;
    sfClock_restart(game->menu->options_clock->clock);
    return (0);
}
