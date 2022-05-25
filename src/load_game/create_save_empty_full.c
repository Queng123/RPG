/*
** EPITECH PROJECT, 2022
** create_save_empty_full.c
** File description:
** function that create texture and sprite of save empty and full
*/

#include "rpg.h"

int create_empty_save(game_t *game, int i, int pos_x)
{
    game->load_game->save_empty[i].text = sfTexture_createFromFile
    ("assets/load_game/New_game_save.png", NULL);
    game->load_game->save_empty[i].spr = sfSprite_create();
    if (game->load_game->save_empty[i].spr == NULL)
        return (84);
    game->load_game->save_empty[i].pos = (sfVector2f){pos_x, 350};
    sfSprite_setPosition(game->load_game->save_empty[i].spr,
    game->load_game->save_empty[i].pos);
    sfSprite_setTexture(game->load_game->save_empty[i].spr,
    game->load_game->save_empty[i].text, sfTrue);
    return (0);
}

int create_full_save(game_t *game, int i, int pos_x)
{
    game->load_game->save_full[i].text = sfTexture_createFromFile
    ("assets/load_game/Load_game_save.png", NULL);
    game->load_game->save_full[i].spr = sfSprite_create();
    if (game->load_game->save_full[i].spr == NULL)
        return (84);
    game->load_game->save_full[i].pos = (sfVector2f){pos_x, 350};
    sfSprite_setPosition(game->load_game->save_full[i].spr,
    game->load_game->save_full[i].pos);
    sfSprite_setTexture(game->load_game->save_full[i].spr,
    game->load_game->save_full[i].text, sfTrue);
    return (0);
}

int create_save_empty_full(game_t *game)
{
    create_empty_save(game, 0, 385);
    create_empty_save(game, 1, 775);
    create_empty_save(game, 2, 1165);
    create_full_save(game, 0, 385);
    create_full_save(game, 1, 775);
    create_full_save(game, 2, 1165);
    return (0);
}
