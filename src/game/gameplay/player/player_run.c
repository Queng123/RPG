/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_run
*/

#include "player.h"

void handle_run(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[4]) {
        game->player->is_running *= -1;
    }
}

int get_speed_running(game_t *game)
{
    if (game->player->is_running == 1) {
        return (5 - game->player->stat->speed);
    } else {
        return (2.5);
    }
}
