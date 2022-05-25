/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_sleep
*/

#include "player.h"

int is_player_pos_valid(map_t *map)
{
    if (map->x_player == 483 && map->y_player == 177) {
        return (0);
    }
    return (1);
}

int is_it_time(int time)
{
    int m = (time - (1440 * (time / 1440))) / 60;

    if (m < 6 || m >= 22) {
        return (0);
    }
    return (1);
}

int can_player_sleep(game_t *game)
{
    int time = game->gameplay->time;

    if (is_player_pos_valid(game->map) == 0
    && is_it_time(time) == 0) {
        return (0);
    }
    return (1);
}

void try_to_sleep(game_t *game)
{
    int *time = &game->gameplay->time;
    int m = (*time - (1440 * (*time / 1440))) / 60;

    if (can_player_sleep(game) != 0) {
        return;
    }
    while (m > 22) {
        *time += 1;
        m = (*time - (1440 * (*time / 1440))) / 60;
    }
    while (m < 7) {
        *time += 1;
        m = (*time - (1440 * (*time / 1440))) / 60;
    }

}

void handle_sleeping(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[6]) {
        try_to_sleep(game);
        return;
    }
}
