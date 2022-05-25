/*
** EPITECH PROJECT, 2022
** lol
** File description:
** zombie_collision
*/

#include "zombies.h"

int get_sign(int x)
{
    if (x >= 0) {
        return (-1);
    } else {
        return (1);
    }
}

void update_zombie_pos(obj_t *zombie)
{
    if (zombie->type == ENEMY) {
        zombie->inertia.x = get_sign(zombie->inertia.x);
        zombie->inertia.y = get_sign(zombie->inertia.y);
    }
}
