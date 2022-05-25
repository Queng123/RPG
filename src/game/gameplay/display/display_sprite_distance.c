/*
** EPITECH PROJECT, 2022
** lol
** File description:
** display_sprite_distance
*/

#include "gameplay.h"

void reset_state(game_t *game)
{
    for (int i = 0; i < NB_ENT; i++) {
        if (game->entitie[i]->state_s == DISPLAYED) {
            game->entitie[i]->state_s = ALIVE;
        }
    }
}

void is_displayble(game_t *game, int y)
{
    obj_t *temp;

    for (int i = 0; i < NB_ENT; i++) {
        temp = game->entitie[i];
        if (temp->state_s == ALIVE && temp->pos.y < y) {
            display_sprite(game, temp->sprite);
            temp->state_s = DISPLAYED;
        }
        try_display_player(game, y);
    }
}

void display_obj_based_on_distance(game_t *game)
{
    for (int y = 10; y < 1080; y = y + 10) {
        is_displayble(game, y);
    }
    reset_state(game);
    game->player->obj->state_s = ALIVE;
}
