/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** current_item
*/

#include "rpg.h"

void restart_clock_boss_animation(game_t *game)
{
    game->boss_s->ck_boss->time =
    sfClock_getElapsedTime(game->boss_s->ck_boss->clock);
    game->boss_s->ck_boss->seconds +=
    game->boss_s->ck_boss->time.microseconds / 1000000.0;
    sfClock_restart(game->boss_s->ck_boss->clock);
}

void restart_clock_boss(game_t *game)
{
    game->boss_s->clock_s->time =
    sfClock_getElapsedTime(game->boss_s->clock_s->clock);
    game->boss_s->clock_s->seconds +=
    game->boss_s->clock_s->time.microseconds / 1000000.0;
    sfClock_restart(game->boss_s->clock_s->clock);
}
