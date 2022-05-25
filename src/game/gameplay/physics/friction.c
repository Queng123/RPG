/*
** EPITECH PROJECT, 2022
** PHYSIQUE_ENGINE
** File description:
** friction
*/

#include "gameplay.h"

void change_state(game_t *game_s)
{
    for (int i = 0; i < NB_ENT; i++) {
        if (game_s->entitie[i]->state_s == NEAR_DEAD) {
            game_s->entitie[i]->state_s = DEAD;
        }
    }
}

void handle_friction(obj_t *obj, float time)
{
    if (time != 0) {
        obj->inertia.x = (obj->inertia.x * COEF_FRI);
        obj->inertia.y = (obj->inertia.y * COEF_FRI);
    }
}
