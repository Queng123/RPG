/*
** EPITECH PROJECT, 2022
** PHYSIQUE_ENGINE
** File description:
** build_bullet
*/

#include "gameplay.h"
#include "build.h"

void build_all_obj(obj_t *res[NB_ENT])
{
    build_barbarian(res);
    build_enemy(res);
}
