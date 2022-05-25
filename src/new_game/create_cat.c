/*
** EPITECH PROJECT, 2022
** create_cat.c
** File description:
** function that create a cat
*/

#include "rpg.h"

int create_cat(game_t *game)
{
    game->new_game->cat.text = sfTexture_createFromFile
    ("assets/new_game/cat.png", NULL);
    game->new_game->cat.spr = sfSprite_create();
    if (game->new_game->cat.spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->cat.spr, game->new_game->cat.text,
    sfTrue);
    game->new_game->cat.pos = (sfVector2f){0, 950};
    sfSprite_setPosition(game->new_game->cat.spr,
    game->new_game->cat.pos);
    game->new_game->cat.rect = (sfIntRect){0, 0, 204, 120};
    sfSprite_setTextureRect(game->new_game->cat.spr, game->new_game->cat.rect);
    game->new_game->cat.clock = sfClock_create();
    if (game->new_game->cat.clock == NULL)
        return (84);
    game->new_game->cat.total_time = 0;
    return (0);
}
