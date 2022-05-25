/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** menu
*/

#include "rpg.h"

void restart_menu_clock(game_t *game)
{
    game->menu->options_clock->time =
    sfClock_getElapsedTime(game->menu->options_clock->clock);
    game->menu->options_clock->seconds +=
    game->menu->options_clock->time.microseconds / 1000000.0;
    sfClock_restart(game->menu->options_clock->clock);
    game->menu->fps_clock->time =
    sfClock_getElapsedTime(game->menu->fps_clock->clock);
    game->menu->fps_clock->seconds +=
    game->menu->fps_clock->time.microseconds / 1000000.0;
    sfClock_restart(game->menu->fps_clock->clock);
    game->generator->generator_clock->time =
    sfClock_getElapsedTime(game->generator->generator_clock->clock);
    game->generator->generator_clock->seconds +=
    game->generator->generator_clock->time.microseconds / 1000000.0;
    sfClock_restart(game->generator->generator_clock->clock);
}

void display_menu(game_t *game)
{
    int arg_list[] = {OPTIONS, LOAD_SAVE, MAIN_MENU, -1};
    void (*game_scene[9])(game_t *game) = {display_options, load_save,
    display_main_menu};

    restart_menu_clock(game);
    for (int i = 0; arg_list[i] != -1; i++) {
        if ((int)game->game_info->scene->actual_menu_scene == arg_list[i]) {
            (*game_scene[i])(game);
        }
    }
}
