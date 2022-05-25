/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** experience_functions
*/

#include "gameplay.h"

void try_level_up(player_t *player)
{
    if (player->exp >= player->step * player->level) {
        player->level++;
        player->exp = 0;
        player->point_competences++;
    }
}

void add_exp(game_t *game, int add)
{
    game->player->exp += add * game->player->stat->intellect;
    try_level_up(game->player);
}
