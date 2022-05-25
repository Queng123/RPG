/*
** EPITECH PROJECT, 2022
** check_hitbox_return_menu_button.C
** File description:
** function that check hitbox of return menu button
*/

#include "rpg.h"

int check_hitbox_return_menu_button(game_t *game)
{
    if ((game->new_game->cursor.x > 390 && game->new_game->cursor.x < 425)
        && (game->new_game->cursor.y > 280 &&
        game->new_game->cursor.y < 320)) {
        game->game_info->scene->actual_scene = MENU;
    }
    return (0);
}
