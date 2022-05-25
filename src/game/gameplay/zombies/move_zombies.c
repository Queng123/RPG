/*
** EPITECH PROJECT, 2022
** lol
** File description:
** move_zombies
*/

#include "zombies.h"

obj_t *get_zombie_based_pos(game_t *game, int x, int y)
{
    for (int i = 0; i < NB_ENT; i++) {
        if (game->entitie[i]->pos.x == x && game->entitie[i]->pos.y == y) {
            return (game->entitie[i]);
        }
    }
    return (NULL);
}

void update_pos(int *x, int *y, int move, axe_t axe)
{
    if (axe == X) {
        *x += move;
    } else {
        *y += move;
    }
}

int try_move_zombie(game_t *game, obj_t *zombie, int move, axe_t axe)
{
    int x = zombie->pos.x;
    int y = zombie->pos.y;
    update_pos(&x, &y, move, axe);

    if (game->map->map_p[y][x] != ' ') {
        return (-1);
    }
    if (axe == X) {
        game->map->map_p[y][x - move] = ' ';
        game->map->map_p[y][x] = 'Z';
        zombie->pos.x += move;
    } else {
        game->map->map_p[y - move][x] = ' ';
        game->map->map_p[y][x] = 'Z';
        zombie->pos.y += move;
    }
    return (0);
}

int is_in_range_and_ready(game_t *game, obj_t *zombie)
{
    int range = 1000;
    obj_t *player = game->player->obj;
    int px = player->pos.x + player->rect.width * player->scale.x / 2;
    int py = player->pos.y + player->rect.height * player->scale.y / 2;
    int distance_x = (zombie->pos.x - game->map->pos_x) * 48 - px;
    int distance_y = (zombie->pos.y - game->map->pos_y) * 48 - py;
    int distance = sqrt((distance_x * distance_x + distance_y * distance_y));

    if (range < distance) {
        return (-1);
    } else if (zombie->clock_move->seconds < 20) {
        return (-1);
    }
    sfClock_restart(zombie->clock_move->clock);
    zombie->clock_move->seconds = 0;
    return (0);
}

void move_to_player(game_t *game, obj_t *zombie)
{
    if (zombie->type != ENEMY || zombie->state_s != ALIVE
    || game->gameplay->pause->display == true) {
        return;
    }
    if (is_in_range_and_ready(game, zombie) == -1) {
        return;
    }
    get_orientation_zombie(game, zombie);
}
