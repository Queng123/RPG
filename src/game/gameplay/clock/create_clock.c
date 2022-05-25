/*
** EPITECH PROJECT, 2022
** physique_engine
** File description:
** main
*/

#include "gameplay.h"

void create_clock(game_t *game_s)
{
    game_s->clock_s->time = sfClock_getElapsedTime(game_s->clock_s->clock);
    game_s->clock_s->seconds = game_s->clock_s->time.microseconds / 100000.0;
}
