/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_zombies
*/

#include "zombies.h"

int get_right_left(int nb)
{
    if (nb < 32) {
        return (32);
    } else if (nb < 64) {
        return (64);
    }
    return (0);
}

void update_sprite_zombie(obj_t *obj)
{
    if (obj->clock_sprite->seconds > 7) {
        sfClock_restart(obj->clock_sprite->clock);
        obj->clock_sprite->seconds = 0;
        obj->rect.left = get_right_left(obj->rect.left + 32);
        sfSprite_setTextureRect(obj->sprite, obj->rect);
    }
}

int is_same_position(obj_t *obj, int x, int y)
{
    if (obj->state_s == DEAD) {
        return (1);
    }
    if (obj->pos.x == x && obj->pos.y == y) {
        return (0);
    }
    return (1);
}

obj_t *get_right_zombie(game_t *game, int x, int y)
{
    for (int i = 0; i < NB_ENT; i++) {
        if (is_same_position(game->entitie[i], x, y) == 0) {
            return (game->entitie[i]);
        }
    }
    return (NULL);
}

void display_zombie(game_t *game, int x, int y)
{
    obj_t *zombie = get_right_zombie(game, x, y);
    sfVector2f pos = {0, 0};
    pos.x = (x - game->map->pos_x) * 48;
    pos.y = (y - game->map->pos_y) * 48;

    if (zombie == NULL) {
        return;
    } else if (zombie->state_s == ALIVE) {
        pos.x -= zombie->rect.width * zombie->scale.x - 24;
        pos.y -= zombie->rect.height * zombie->scale.y - 24;
        sfSprite_setPosition(zombie->sprite, pos);
        display_sprite(game, zombie->sprite);
    }
}
