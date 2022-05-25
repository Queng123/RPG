/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_game_bar
*/

#include "rpg.h"

void display_game_bar(game_t *game)
{
    display_bg(game->gameplay->background[0], game->game_info->window);
    display_bg(game->gameplay->background[1], game->game_info->window);
}
