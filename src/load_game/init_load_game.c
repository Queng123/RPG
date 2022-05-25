/*
** EPITECH PROJECT, 2022
** init_load_game.c
** File description:
** function that init all value for load_game
*/

#include "rpg.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int init_load_game(game_t *game)
{
    game->load_game = malloc(sizeof(load_game_t));
    if (game->load_game == NULL)
        return (ERROR);
    init_value_load_game(game);
    create_support_save(game);
    create_save_empty_full(game);
    create_delete_save(game);
    check_save_file(game);
    return (0);
}
