/*
** EPITECH PROJECT, 2022
** check_hitbox_delete_save.c
** File description:
** function that check hitbox of delete save menu
*/

#include "rpg.h"

int check_hitbox_delete_save(game_t *game)
{
    if ((game->new_game->cursor.x > 754 && game->new_game->cursor.x < 936)
        && (game->new_game->cursor.y > 579 && game->new_game->cursor.y < 642)) {
        game->load_game->save[game->load_game->nb_save] = false;
        game->load_game->delete = false;
        delete_data_file(game);
    }
    if ((game->new_game->cursor.x > 994 && game->new_game->cursor.x < 1177)
        && (game->new_game->cursor.y > 579 && game->new_game->cursor.y < 642)) {
        game->load_game->delete = false;
    }
    return (0);
}
