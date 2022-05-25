/*
** EPITECH PROJECT, 2022
** check_hitbox_character_color.c
** File description:
** file with function that handle the color character hitbox
*/

#include "rpg.h"

int check_hitbox_last_color(game_t *game)
{
    if ((game->new_game->cursor.x > 857 && game->new_game->cursor.x < 917)
        && (game->new_game->cursor.y > 441 && game->new_game->cursor.y < 497)) {
        game->new_game->color = 3;
        return (1);
    }
    if ((game->new_game->cursor.x > 857 && game->new_game->cursor.x < 917)
        && (game->new_game->cursor.y > 500 && game->new_game->cursor.y < 556)) {
        game->new_game->color = 4;
        return (1);
    }
    return (0);
}

int check_hitbox_first_color(game_t *game)
{
    if ((game->new_game->cursor.x > 857 && game->new_game->cursor.x < 917)
        && (game->new_game->cursor.y > 315 && game->new_game->cursor.y < 375)) {
        game->new_game->color = 1;
        return (0);
    }
    if ((game->new_game->cursor.x > 857 && game->new_game->cursor.x < 917)
        && (game->new_game->cursor.y > 381 && game->new_game->cursor.y < 435)) {
        game->new_game->color = 2;
        return (0);
    }
    if (check_hitbox_last_color(game) == 1)
        return (0);
    return (0);
}
