/*
** EPITECH PROJECT, 2022
** lol
** File description:
** spawn_zombies
*/

#include "zombies.h"

int find_zombie(game_t *game)
{
    for (int i = 0; i < NB_ENT; i++) {
        if (game->entitie[i]->state_s == DEAD) {
            return (i);
        }
    }
    return (-1);
}

int is_player_in_village(map_t *map)
{
    if (map->pos_y > 156 && map->pos_x > 339) {
        return (0);
    }
    return (1);
}

int get_ratio(int time)
{
    int m = (time - (1440 * time / 1440)) / 60;

    if (m < 6 || m >= 22) {
        return (10);
    }
    return (15);
}

int is_spawn_valid(map_t *map, obj_t *zombie)
{
    int x = zombie->pos.x;
    int y = zombie->pos.y;

    if (x < 0 || x >= map->max_x || y < 0 || y >= map->max_y
    || (y > 156 && x > 339)) {
        return (1);
    }
    if (map->map_p[y][x] == ' ') {
        map->map_p[y][x] = 'Z';
        return (0);
    }
    return (1);
}

void spawn_zombies(game_t *game)
{
    int idx = find_zombie(game);
    int ratio = get_ratio(game->gameplay->time);

    if (game->gameplay->pause->display == true
    || is_player_in_village(game->map) == 0)
        return;
    if (rand() % ratio != 7 || idx == -1) {
        return;
    }
    generate_random_pos(game->map, game->entitie[idx]);
    if (is_spawn_valid(game->map, game->entitie[idx]) == 0) {
        game->entitie[idx]->state_s = ALIVE;
        game->entitie[idx]->hp = 10;
        sfSprite_setRotation(game->entitie[idx]->sprite, 0);
    } else {
        game->entitie[idx]->pos = (sfVector2f) {10000, 10000};
        game->entitie[idx]->state_s = DEAD;
    }
}
