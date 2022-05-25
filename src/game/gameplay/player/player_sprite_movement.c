/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_sprite_movement
*/

#include "player.h"

void update_sprite_player_move(obj_t *temp)
{
    if (temp->clock_sprite->seconds > 4) {
        temp->rect.left += 30;
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        temp->clock_sprite->seconds = 0;
        sfClock_restart(temp->clock_sprite->clock);
    }
}
