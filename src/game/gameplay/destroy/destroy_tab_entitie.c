/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-lylian.hay
** File description:
** destroy_tab_entitie
*/

#include "gameplay.h"

void destroy_tab_entitie(obj_t *obj[NB_ENT])
{
    for (int i = 0; i < NB_ENT; i++) {
        sfTexture_destroy(obj[i]->texture);
        sfSprite_destroy(obj[i]->sprite);
        sfClock_destroy(obj[i]->clock_sprite->clock);
        free(obj[i]->clock_sprite);
        sfClock_destroy(obj[i]->clock_attack->clock);
        free(obj[i]->clock_attack);
        free(obj[i]);
    }
}
