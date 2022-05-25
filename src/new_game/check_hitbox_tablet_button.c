/*
** EPITECH PROJECT, 2022
** check_hitbox_tablet_button.c
** File description:
** function that check the hitbox of main button of tablet
*/

#include "rpg.h"

int check_hitbox_tablet_button(game_t *game)
{
    if ((game->new_game->cursor.x > 1645 && game->new_game->cursor.x < 1695)
        && (game->new_game->cursor.y > 332 && game->new_game->cursor.y < 375)) {
        restore_default_rotation_character(game);
        game->game_info->scene->actual_scene = MENU;
        return (0);
    }
    if ((game->new_game->cursor.x > 1641 && game->new_game->cursor.x < 1700)
        && (game->new_game->cursor.y > 460 && game->new_game->cursor.y < 560)) {
        restore_default_rotation_character(game);
        game->game_info->scene->actual_scene = MENU;
        return (0);
    }
    return (0);
}
