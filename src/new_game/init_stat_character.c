/*
** EPITECH PROJECT, 2022
** init_stat_character.c
** File description:
** function that init stat of player
*/

#include "rpg.h"

int init_stat_researcher(game_t *game)
{
    game->new_game->stat_charac[3].intellect = 5;
    game->new_game->stat_charac[3].shoot = 3;
    game->new_game->stat_charac[3].speed = 4;
    game->new_game->stat_charac[3].stamina = 2;
    game->new_game->stat_charac[3].strenght = 2;
    return (0);
}

int init_stat_sporty(game_t *game)
{
    game->new_game->stat_charac[1].intellect = 3;
    game->new_game->stat_charac[1].shoot = 3;
    game->new_game->stat_charac[1].speed = 5;
    game->new_game->stat_charac[1].stamina = 4;
    game->new_game->stat_charac[1].strenght = 3;
    return (0);
}

int init_stat_cop(game_t *game)
{
    game->new_game->stat_charac[2].intellect = 2;
    game->new_game->stat_charac[2].shoot = 3;
    game->new_game->stat_charac[2].speed = 3;
    game->new_game->stat_charac[2].stamina = 4;
    game->new_game->stat_charac[2].strenght = 5;
    return (0);
}

int init_stat_soldier(game_t *game)
{
    game->new_game->stat_charac[0].intellect = 1;
    game->new_game->stat_charac[0].shoot = 5;
    game->new_game->stat_charac[0].speed = 3;
    game->new_game->stat_charac[0].stamina = 4;
    game->new_game->stat_charac[0].strenght = 4;
    return (0);
}

int init_stat_character(game_t *game)
{
    init_stat_cop(game);
    init_stat_researcher(game);
    init_stat_soldier(game);
    init_stat_sporty(game);
    return (0);
}
