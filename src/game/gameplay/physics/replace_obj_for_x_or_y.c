/*
** EPITECH PROJECT, 2022
** PHYSIQUE_ENGINE
** File description:
** find_collisions
*/

#include "gameplay.h"

void replace_obj_for_x_obj1(obj_t *obj1, obj_t *obj2, int temp)
{
    obj2->inertia.x = (obj2->inertia.x + obj1->inertia.x) * obj2->abs;
    obj1->inertia.x = (obj1->inertia.x + temp) * obj1->abs;
    obj1->pos.x -= (obj2->pos.x -get_hitbox_size(obj1, X)) / 40;
}

void replace_obj_for_x_obj2(obj_t *obj1, obj_t *obj2, int temp)
{
    obj1->inertia.x = (obj1->inertia.x + obj2->inertia.x) * obj1->abs;
    obj2->inertia.x = (obj2->inertia.x + temp) * obj2->abs;
    obj2->pos.x -= (obj1->pos.x - get_hitbox_size(obj2, X)) / 40;
}

void replace_obj_for_y_obj1(obj_t *obj1, obj_t *obj2, int temp)
{
    obj2->inertia.y = (obj2->inertia.y + obj1->inertia.y) * obj2->abs;
    obj1->inertia.y = (obj1->inertia.y + temp) * obj1->abs;
    obj1->pos.y -= (obj2->pos.y - get_hitbox_size(obj1, Y)) / 40;
}

void replace_obj_for_y_obj2(obj_t *obj1, obj_t *obj2, int temp)
{
    obj1->inertia.y = (obj1->inertia.y + obj2->inertia.y) * obj1->abs;
    obj2->inertia.y = (obj2->inertia.y + temp) * obj2->abs;
    obj2->pos.y -= (obj1->pos.y - get_hitbox_size(obj2, Y)) / 40;
}
