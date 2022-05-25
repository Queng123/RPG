/*
** EPITECH PROJECT, 2022
** physique_engine
** File description:
** player
*/

#include "gameplay.h"

void manage_clock_obj_sprite(int i, obj_t *temp, game_t *game)
{
    temp = game->entitie[i];
    temp->clock_sprite->time =
    sfClock_getElapsedTime(temp->clock_sprite->clock);
    temp->clock_sprite->seconds =
    temp->clock_sprite->time.microseconds / 100000.0;
    temp->clock_attack->time =
    sfClock_getElapsedTime(temp->clock_attack->clock);
    temp->clock_attack->seconds =
    temp->clock_attack->time.microseconds / 100000.0;
    temp->clock_move->time =
    sfClock_getElapsedTime(temp->clock_move->clock);
    temp->clock_move->seconds =
    temp->clock_move->time.microseconds / 100000.0;
}

void manage_clock_obj(game_t *game)
{
    obj_t *temp = game->player->obj;
    temp->clock_sprite->time =
    sfClock_getElapsedTime(temp->clock_sprite->clock);
    temp->clock_sprite->seconds =
    temp->clock_sprite->time.microseconds / 100000.0;
    temp->clock_attack->time =
    sfClock_getElapsedTime(temp->clock_attack->clock);
    temp->clock_attack->seconds =
    temp->clock_attack->time.microseconds / 100000.0;
    temp->clock_move->time = sfClock_getElapsedTime(temp->clock_move->clock);
    temp->clock_move->seconds = temp->clock_move->time.microseconds / 100000.0;
    game->clock_s->time = sfClock_getElapsedTime(game->clock_s->clock);
    game->clock_s->seconds = game->clock_s->time.microseconds / 100000.0;
    for (int i = 0; i < NB_ENT; i++) {
        manage_clock_obj_sprite(i, temp, game);
    }
}
