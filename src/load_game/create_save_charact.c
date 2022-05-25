/*
** EPITECH PROJECT, 2022
** create_save_charact.c
** File description:
** function that create charact of the save
*/

#include "rpg.h"

int create_save_charact(game_t *game, int i, char *filepath, int pos_x)
{
    game->load_game->save_charact[i].text = sfTexture_createFromFile
    (filepath, NULL);
    game->load_game->save_charact[i].spr = sfSprite_create();
    if (game->load_game->save_charact[i].spr == NULL)
        return (84);
    game->load_game->save_charact[i].pos = (sfVector2f){pos_x, 400};
    game->load_game->save_charact[i].scale = (sfVector2f){7, 7};
    sfSprite_setScale(game->load_game->save_charact[i].spr,
    game->load_game->save_charact[i].scale);
    sfSprite_setPosition(game->load_game->save_charact[i].spr,
    game->load_game->save_charact[i].pos);
    sfSprite_setTexture(game->load_game->save_charact[i].spr,
    game->load_game->save_charact[i].text, sfTrue);
    game->load_game->save_charact[i].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->load_game->save_charact[i].spr,
    game->load_game->save_charact[i].rect);
    return (0);
}
