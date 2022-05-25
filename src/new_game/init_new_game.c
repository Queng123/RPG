/*
** EPITECH PROJECT, 2022
** init_new_game.c
** File description:
** function that init new game assets
*/

#include "rpg.h"

int init_value_new_game(game_t *game)
{
    game->new_game->name[0] = "Quentin Brejoin";
    game->new_game->name[1] = "Lylian Hay";
    game->new_game->name[2] = "Timothee Lesellier";
    game->new_game->name[3] = "Matthias Gaste";
    game->new_game->class = 0;
    game->new_game->top_size = 0;
    game->new_game->color = 0;
    init_stat_character(game);
    return (0);
}

int init_new_game(game_t *game)
{
    game->new_game = malloc(sizeof(new_game_t));
    if (game->new_game == NULL)
        return (ERROR);
    init_value_new_game(game);
    if (create_cat(game) == 84)
        return (84);
    if (create_class(game) == 84)
        return (84);
    if (create_all_character(game) == 84)
        return (84);
    return (0);
}
