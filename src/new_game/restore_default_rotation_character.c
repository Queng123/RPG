/*
** EPITECH PROJECT, 2022
** restore_default_rotation_character.c
** File description:
** function that restore default rotation character and also color
*/

#include "rpg.h"

int restore_default_rotation_character(game_t *game)
{
    for (int a = 0; a != 19; a++) {
        game->new_game->character[a].rect.top = 0;
        if (game->new_game->character[a].spr != NULL)
            sfSprite_setTextureRect(game->new_game->character[a].spr,
            game->new_game->character[a].rect);
    }
    game->new_game->color = 0;
    return (0);
}
