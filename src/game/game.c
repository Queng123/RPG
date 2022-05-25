/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game
*/

#include "rpg.h"

void restart_tablet_clock(game_t *game)
{
    game->gameplay->tablet->tablet_clock->time =
    sfClock_getElapsedTime(game->gameplay->tablet->tablet_clock->clock);
    game->gameplay->tablet->tablet_clock->seconds +=
    game->gameplay->tablet->tablet_clock->time.microseconds / 1000000.0;
    sfClock_restart(game->gameplay->tablet->tablet_clock->clock);
    game->gameplay->tablet->screen_clock->time =
    sfClock_getElapsedTime(game->gameplay->tablet->screen_clock->clock);
    game->gameplay->tablet->screen_clock->seconds +=
    game->gameplay->tablet->screen_clock->time.microseconds / 1000000.0;
    sfClock_restart(game->gameplay->tablet->screen_clock->clock);
}

void restart_game_clock(game_t *game)
{
    game->clock_s->time = sfClock_getElapsedTime(game->clock_s->clock);
    game->clock_s->seconds = game->clock_s->time.microseconds / 100000.0;
    sfClock_restart(game->clock_s->clock);
    game->gameplay->timer->time =
    sfClock_getElapsedTime(game->gameplay->timer->clock);
    game->gameplay->timer->seconds +=
    game->gameplay->timer->time.microseconds / 1000000.0;
    sfClock_restart(game->gameplay->timer->clock);
    restart_tablet_clock(game);
    game->generator->generator_clock->time =
    sfClock_getElapsedTime(game->generator->generator_clock->clock);
    game->generator->generator_clock->seconds +=
    game->generator->generator_clock->time.microseconds / 1000000.0;
    sfClock_restart(game->generator->generator_clock->clock);
    game->quest->clock->time =
    sfClock_getElapsedTime(game->quest->clock->clock);
    game->quest->clock->seconds +=
    game->quest->clock->time.microseconds / 1000000.0;
    sfClock_restart(game->quest->clock->clock);
}

void display_game(game_t *game)
{
    int arg_list[] = {PAUSE, INTRO, INVENTORY, GAMEPLAY, BOSS, -1};
    void (*game_scene[9])(game_t *game) = {display_pause, display_intro,
    display_inventory, play_game, display_boss};

    restart_game_clock(game);
    for (int i = 0; arg_list[i] != -1; i++) {
        if ((int)game->game_info->scene->actual_game_scene == arg_list[i]) {
            (*game_scene[i])(game);
        }
    }
}
