/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** get_obj_dead
*/

#include "zombies.h"

int get_zombies_dead(obj_t *obj)
{
    int y = obj->pos.y + (obj->rect.height * obj->scale.y);
    y += obj->rect.width / 2;
    if (!(obj->hp <= 0 && obj->type == ENEMY && obj->state_s == ALIVE)) {
        return (1);
    }
    sfClock_restart(obj->clock_sprite->clock);
    obj->clock_sprite->seconds = 0;
    obj->state_s = NEAR_DEAD;
    return (0);
}

void check_if_dead(game_t *game)
{
    for (int i = 0; i < NB_ENT; i++) {
        if (get_zombies_dead(game->entitie[i]) == 0) {
            try_add_item(game, MONEY, 50);
            add_exp(game, 5);
        }
        if (game->entitie[i]->hp <= 0 && game->entitie[i]->state_s == ALIVE) {
            game->entitie[i]->state_s = DEAD;
        }
    }
}
