/*
** EPITECH PROJECT, 2022
** restart_default_value_game.c
** File description:
** function that restart all var in game
*/

#include "rpg.h"

int restart_default_value_game(game_t *game)
{
    game->map->map_p[game->map->y_player][game->map->x_player] = ' ';
    game->map->pos_x = 461;
    game->map->pos_y = 164;
    game->map->x_player = 483;
    game->map->y_player = 177;
    game->map->map_p[game->map->y_player][game->map->x_player] = 'P';
    game->quest->current_level_quest = -1;
    game->quest->item_collected = -1;
    game->gameplay->pause->display = false;
    for (int i = 1; i < 10; i++)
        game->gameplay->tablet->button[i]->status = 0;
    game->gameplay->tablet->button[0]->status = 1;
    game->quest->mayor_talk = 0;
    game->quest->current_level_quest = 0;
    game->quest->item_collected = 0;
    reset_map_as_a_virgin(game);
    return (0);
}
