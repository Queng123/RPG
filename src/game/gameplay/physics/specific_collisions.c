/*
** EPITECH PROJECT, 2022
** lol
** File description:
** specific_collisions
*/

#include "gameplay.h"
#include "physic.h"

int is_player_hit(obj_t *obj1, obj_t *obj2)
{
    if (obj1->type == PLAYER && obj2->type == ENEMY) {
        obj2->inertia = (sfVector2f) {0, 0};
        return (0);
    }
    if (obj1->type == ENEMY && obj2->type == PLAYER) {
        obj1->inertia = (sfVector2f) {0, 0};
        return (0);
    }
    return (0);
}

int is_building_hit(obj_t *obj1, obj_t *obj2)
{
    if (obj1->type == IMMU && obj2->type != IMMU) {
        update_zombie_pos(obj2);
        return (1);
    }
    if (obj1->type != IMMU && obj2->type == IMMU) {
        update_zombie_pos(obj1);
        return (1);
    }
    return (0);
}
