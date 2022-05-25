/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_attack
*/

#include "player.h"
#include <stdio.h>
#include <math.h>

int is_obj_click(game_t *game, obj_t *obj, sfMouseButtonEvent mouse)
{
    int x = (obj->pos.x - game->map->pos_x) * 48 - 48;
    int y = (obj->pos.y - game->map->pos_y) * 48 - 48;
    int mx_x = x + obj->rect.width * obj->scale.x;
    int mx_y = y + obj->rect.height * obj->scale.y;
    int mx = mouse.x;
    int my = mouse.y;

    if (mx > x && mx < mx_x && my > y && my < mx_y) {
        return (0);
    }
    return (1);
}
