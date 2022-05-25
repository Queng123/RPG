/*
** EPITECH PROJECT, 2022
** lol
** File description:
** display_player
*/

#include "player.h"

void try_display_player(game_t *game, int y)
{
    if (game->player->obj->state_s == ALIVE && game->player->obj->pos.y < y) {
        display_sprite(game, game->player->obj->sprite);
        game->player->obj->state_s = DISPLAYED;
    }
}
