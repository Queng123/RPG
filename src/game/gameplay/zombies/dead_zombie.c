/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** dead_zombie
*/

#include "zombies.h"

void do_dead_zombie_animation(game_t *game, obj_t *obj)
{
    sfVector2f pos = obj->pos;
    int y = obj->pos.y;
    int x = obj->pos.x;
    pos.x = (x - game->map->pos_x) * 48 - obj->rect.width * obj->scale.x + 24;
    pos.y = (y - game->map->pos_y) * 48 - obj->rect.height * obj->scale.y + 96;

    if (!(obj->type == ENEMY && obj->state_s == NEAR_DEAD)) {
        return;
    }
    if (obj->clock_sprite->seconds < 40) {
        sfSprite_setRotation(obj->sprite, -90);
        sfSprite_setPosition(obj->sprite, pos);
        display_sprite(game, obj->sprite);
    } else {
        obj->state_s = DEAD;
        game->map->map_p[y][x] = ' ';
    }
}

void display_near_dead_obj(game_t *game)
{
    for (int i = 0; i < NB_ENT; i++) {
        do_dead_zombie_animation(game, game->entitie[i]);
    }
}
