/*
** EPITECH PROJECT, 2022
** send_stat_character.c
** File description:
** function that send information on character choose
*/

#include "rpg.h"

int send_stat_character(game_t *game)
{
    game->player->stat = malloc(sizeof(stat_t));
    game->player->stat->speed = game->new_game->stat_charac
    [game->new_game->class].speed;
    game->player->stat->stamina = game->new_game->stat_charac
    [game->new_game->class].stamina;
    game->player->stat->strength = game->new_game->stat_charac
    [game->new_game->class].strenght;
    game->player->stat->intellect = game->new_game->stat_charac
    [game->new_game->class].intellect;
    game->player->stat->shoot = game->new_game->stat_charac
    [game->new_game->class].shoot;
    return (0);
}
