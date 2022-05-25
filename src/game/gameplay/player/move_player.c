/*
** EPITECH PROJECT, 2022
** lol
** File description:
** move_player
*/

#include "physic.h"
#include "player.h"

int move_map(game_t * game_s, int move, axe_t axe)
{
    int new_pos_x = game_s->map->pos_x + move;
    int max_x = game_s->map->max_x;
    int new_pos_y = game_s->map->pos_y + move;
    int max_y = game_s->map->max_y;

    if (axe == X && new_pos_x > 0 && new_pos_x < max_x) {
        game_s->map->pos_x += move;
        return (0);
    }
    if (axe == Y && new_pos_y > 0 && new_pos_y < max_y) {
        game_s->map->pos_y += move;
        return (0);
    }
    return (-1);
}

void update_obj_pos(obj_t *obj, int move, axe_t axe)
{
    if (axe == X) {
        obj->pos.x += move;
    }
    if (axe == Y) {
        obj->pos.y += move;
    }
}

void update_obj_tab(game_t *game, int move, axe_t axe)
{
    for (int i = 0; i < NB_ENT; i++) {
        update_obj_pos(game->entitie[i], move, axe);
    }
}

int is_player_move_valid(game_t *game, int move, axe_t axe)
{
    int x = game->map->x_player;
    int y = game->map->y_player;

    if (axe == X) {
        x += move;
    } else {
        y += move;
    }
    if (game->map->map_p[y][x] != ' ') {
        return (-1);
    }
    if (axe == X) {
        game->map->map_p[y][x - move] = ' ';
        game->map->x_player += move;
        game->map->map_p[y][x] = 'P';
    } else {
        game->map->map_p[y - move][x] = ' ';
        game->map->y_player += move;
        game->map->map_p[y][x] = 'P';
    }
    return (0);
}

void move_entitie(game_t *game, int move, axe_t axe)
{
    if (is_player_move_valid(game, move, axe) == -1) {
        return;
    } else if (move_map(game, move, axe) == -1) {
        return;
    }
}
