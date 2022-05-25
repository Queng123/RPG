/*
** EPITECH PROJECT, 2022
** create_support_save.c
** File description:
** function that create texture and sprite of support of save
*/

#include "rpg.h"

int create_support_save(game_t *game)
{
    game->load_game->support_save.text = sfTexture_createFromFile
    ("assets/load_game/Load_save.png", NULL);
    game->load_game->support_save.spr = sfSprite_create();
    if (game->load_game->support_save.spr == NULL)
        return (84);
    game->load_game->support_save.pos = (sfVector2f){344, 261};
    sfSprite_setPosition(game->load_game->support_save.spr,
    game->load_game->support_save.pos);
    sfSprite_setTexture(game->load_game->support_save.spr,
    game->load_game->support_save.text, sfTrue);
    return (0);
}
