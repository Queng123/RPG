/*
** EPITECH PROJECT, 2022
** create_delete_save.c
** File description:
** function that create texture and sprite of delete save
*/

#include "rpg.h"

int create_delete_save(game_t *game)
{
    game->load_game->delete_save.text = sfTexture_createFromFile
    ("assets/load_game/Delete_save.png", NULL);
    game->load_game->delete_save.spr = sfSprite_create();
    if (game->load_game->delete_save.spr == NULL)
        return (84);
    game->load_game->delete_save.pos = (sfVector2f){640, 400};
    sfSprite_setPosition(game->load_game->delete_save.spr,
    game->load_game->delete_save.pos);
    sfSprite_setTexture(game->load_game->delete_save.spr,
    game->load_game->delete_save.text, sfTrue);
    return (0);
}
