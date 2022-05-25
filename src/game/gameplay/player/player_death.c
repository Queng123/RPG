/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_death
*/

#include "player.h"

void handle_player_death(game_t *game)
{
    int x = game->map->x_player;
    int y = game->map->y_player;

    if (game->player->obj->hp <= 0) {
        game->map->x_player = 472;
        game->map->y_player = 210;
        game->map->pos_x = 450;
        game->map->pos_y = 197;
        game->player->obj->hp = game->player->health->max_score;
        update_health_bar(game->player->obj, game->player->health);
        game->map->map_p[y][x] = ' ';
        x = game->map->x_player;
        y = game->map->y_player;
        game->map->map_p[y][x] = 'P';
    }
}
