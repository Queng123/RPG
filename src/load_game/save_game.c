/*
** EPITECH PROJECT, 2022
** save_game.c
** File description:
** function that save the advanced in game
*/

#include "rpg.h"
#include "unistd.h"
#include <sys/stat.h>
#include <stdlib.h>
#include <fcntl.h>

int save_game(game_t *game)
{
    char *array[] = {"data/save_1.txt", "data/save_2.txt", "data/save_3.txt"};

    if (game->load_game->load_save != -1) {
        save_data_in_file(array[game->load_game->load_save], game);
        game->load_game->save[game->load_game->load_save] = true;
        check_save_file(game);
        return (0);
    }
    for (int i = 0; i < 3; i++) {
        if (game->load_game->save[i] == false) {
            save_data_in_file(array[i], game);
            game->load_game->save[i] = true;
            check_save_file(game);
            return (0);
        }
    }
    return (0);
}
