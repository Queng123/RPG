/*
** EPITECH PROJECT, 2022
** check_hitbox_choose_class.c
** File description:
** function that check the hitbox of the button choose class
*/

#include "rpg.h"

int check_hitbox_choose_class(game_t *game)
{
    if ((game->new_game->cursor.x > 565 && game->new_game->cursor.x < 590)
        && (game->new_game->cursor.y > 267 && game->new_game->cursor.y < 307)) {
        game->new_game->class--;
        restore_default_rotation_character(game);
    }
    if ((game->new_game->cursor.x > 815 && game->new_game->cursor.x < 848)
        && (game->new_game->cursor.y > 265 && game->new_game->cursor.y < 308)) {
        game->new_game->class++;
        restore_default_rotation_character(game);
    }
    if (game->new_game->class == -1)
        game->new_game->class = 3;
    if (game->new_game->class == 4)
        game->new_game->class = 0;
    return (0);
}
