/*
** EPITECH PROJECT, 2022
** PHYSIQUE_ENGINE
** File description:
** find_collisions
*/

#include "gameplay.h"

int get_hitbox_size(obj_t *obj, axe_t idx)
{
    int res = 0;

    if (idx == X) {
        res = (obj->pos.x + (obj->hitbox.width * obj->scale.x));
        return (res);
    } else {
        res = (obj->pos.y + (obj->hitbox.height * obj->scale.y));
        return (res);
    }
}

int get_hitbox_mid(obj_t *obj, axe_t idx)
{
    int res = 0;

    if (idx == X) {
        res = (obj->pos.x + (obj->hitbox.width * obj->scale.x / 2));
        return (res);
    } else {
        res = (obj->pos.y + (obj->hitbox.height * obj->scale.y / 2));
        return (res);
    }
}
