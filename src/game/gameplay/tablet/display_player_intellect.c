/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_player_intellect
*/

#include "rpg.h"

void display_player_intellect(game_t *game)
{
    char *str = NULL;

    str = int_to_char(game->player->stat->intellect);
    if (str != NULL) {
        sfText_setString(game->gameplay->tablet->text[6]->text, str);
        display_text_info(game->gameplay->tablet->text[6],
        game->game_info->window);
    }
    if (my_strcmp("0", str) != 0)
        free(str);
}
