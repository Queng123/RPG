/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** spawn_zombies_function
*/

#include "zombies.h"

sfIntRect get_spawn_rect(map_t *map, int idx)
{
    sfIntRect top = {map->pos_x - 10, map->pos_y - 10,
    map->pos_x + 130, map->pos_y + 77};
    sfIntRect bott = {map->pos_x, map->pos_y + 67,
    map->pos_x + 130, map->pos_y + 77};
    sfIntRect left = {map->pos_x - 10, map->pos_y,
    map->pos_x - 10, map->pos_y + 67};
    sfIntRect right = {map->pos_x + 130, map->pos_y,
    map->pos_x + 130 , map->pos_y + 67};

    if (idx == 0) {
        return (top);
    } else if (idx == 1) {
        return (bott);
    }
    if (idx == 2) {
        return (left);
    }
    return (right);
}

void try_something(map_t *map, obj_t *obj, int idx)
{
    if (idx == 0) {
        obj->pos.x = map->pos_x + rand() % 120;
        obj->pos.y = map->pos_y - rand() % 15;
    } else if (idx == 1) {
        obj->pos.x = map->pos_x + rand() % 120;
        obj->pos.y = map->pos_y + 67 + rand() % 15;
    }
    if (idx == 2) {
        obj->pos.x = map->pos_x - rand() % 15;
        obj->pos.y = map->pos_y + rand() % 67;
    } else if (idx == 3) {
        obj->pos.x = map->pos_x + 120 + rand() % 15;
        obj->pos.y = map->pos_y + rand() % 67;
    }
}

void generate_random_pos(map_t *map, obj_t *obj)
{
    int random = rand() % 4;

    try_something(map, obj, random);
}
