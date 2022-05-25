/*
** EPITECH PROJECT, 2022
** create_character_soldier.c
** File description:
** file with all function that create soldier and differents colors
*/

#include "rpg.h"

int create_soldier_basic(game_t *game)
{
    game->new_game->character[0].text = sfTexture_createFromFile
    ("assets/new_game/Soldier_basic.png", NULL);
    game->new_game->character[0].spr = sfSprite_create();
    if (game->new_game->character[0].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[0].spr,
    game->new_game->character[0].text, sfTrue);
    game->new_game->character[0].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[0].spr,
    game->new_game->character[0].pos);
    sfSprite_setScale(game->new_game->character[0].spr, (sfVector2f){8, 8});
    game->new_game->character[0].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[0].spr,
    game->new_game->character[0].rect);
    return (0);
}

int create_soldier_red(game_t *game)
{
    game->new_game->character[1].text = sfTexture_createFromFile
    ("assets/new_game/Soldier_red.png", NULL);
    game->new_game->character[1].spr = sfSprite_create();
    if (game->new_game->character[1].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[1].spr,
    game->new_game->character[1].text, sfTrue);
    game->new_game->character[1].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[1].spr,
    game->new_game->character[1].pos);
    sfSprite_setScale(game->new_game->character[1].spr, (sfVector2f){8, 8});
    game->new_game->character[1].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[1].spr,
    game->new_game->character[1].rect);
    return (0);
}

int create_soldier_blue(game_t *game)
{
    game->new_game->character[2].text = sfTexture_createFromFile
    ("assets/new_game/Soldier_blue.png", NULL);
    game->new_game->character[2].spr = sfSprite_create();
    if (game->new_game->character[2].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[2].spr,
    game->new_game->character[2].text, sfTrue);
    game->new_game->character[2].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[2].spr,
    game->new_game->character[2].pos);
    sfSprite_setScale(game->new_game->character[2].spr, (sfVector2f){8, 8});
    game->new_game->character[2].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[2].spr,
    game->new_game->character[2].rect);
    return (0);
}

int create_soldier_green(game_t *game)
{
    game->new_game->character[3].text = sfTexture_createFromFile
    ("assets/new_game/Soldier_green.png", NULL);
    game->new_game->character[3].spr = sfSprite_create();
    if (game->new_game->character[3].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[3].spr,
    game->new_game->character[3].text, sfTrue);
    game->new_game->character[3].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[3].spr,
    game->new_game->character[3].pos);
    sfSprite_setScale(game->new_game->character[3].spr, (sfVector2f){8, 8});
    game->new_game->character[3].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[3].spr,
    game->new_game->character[3].rect);
    return (0);
}

int create_soldier_pink(game_t *game)
{
    game->new_game->character[4].text = sfTexture_createFromFile
    ("assets/new_game/Soldier_pink.png", NULL);
    game->new_game->character[4].spr = sfSprite_create();
    if (game->new_game->character[4].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[4].spr,
    game->new_game->character[4].text, sfTrue);
    game->new_game->character[4].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[4].spr,
    game->new_game->character[4].pos);
    sfSprite_setScale(game->new_game->character[4].spr, (sfVector2f){8, 8});
    game->new_game->character[4].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[4].spr,
    game->new_game->character[4].rect);
    return (0);
}
