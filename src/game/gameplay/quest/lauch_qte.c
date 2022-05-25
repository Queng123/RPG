/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** lauch_qte
*/

#include "gameplay.h"

void try_launch_qte(game_t *game)
{
    int x = game->map->x_player;
    int y = game->map->y_player;

    if (x >= 491 && x <= 493 && y == 61
    && game->quest->item_collected >= 2
    && game->quest->current_level_quest >= 2) {
        game->boss_s->menu_boss = 1;
        game->game_info->scene->actual_game_scene = BOSS;
    }
}

void handle_mine_entrance(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[6]) {
        try_launch_qte(game);
    }
}
