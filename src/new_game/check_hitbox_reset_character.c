/*
** EPITECH PROJECT, 2022
** check_hitbox_reset_character.c
** File description:
** function that check the hitbox of reset button character
*/

#include "rpg.h"

int check_hitbox_reset_character(game_t *game)
{
    if ((game->new_game->cursor.x > 863 && game->new_game->cursor.x < 917)
        && (game->new_game->cursor.y > 563 && game->new_game->cursor.y < 619)) {
        restore_default_rotation_character(game);
        return (0);
    }
    return (0);
}
