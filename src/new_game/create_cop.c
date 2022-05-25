/*
** EPITECH PROJECT, 2022
** create_character_cop.c
** File description:
** file with all function that create cop and differents colors
*/

#include "rpg.h"

int create_cop_basic(game_t *game)
{
    game->new_game->character[10].text = sfTexture_createFromFile
    ("assets/new_game/Cop_basic.png", NULL);
    game->new_game->character[10].spr = sfSprite_create();
    if (game->new_game->character[10].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[10].spr,
    game->new_game->character[10].text, sfTrue);
    game->new_game->character[10].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[10].spr,
    game->new_game->character[10].pos);
    sfSprite_setScale(game->new_game->character[10].spr, (sfVector2f){8, 8});
    game->new_game->character[10].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[10].spr,
    game->new_game->character[10].rect);
    return (0);
}

int create_cop_red(game_t *game)
{
    game->new_game->character[11].text = sfTexture_createFromFile
    ("assets/new_game/Cop_red.png", NULL);
    game->new_game->character[11].spr = sfSprite_create();
    if (game->new_game->character[11].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[11].spr,
    game->new_game->character[11].text, sfTrue);
    game->new_game->character[11].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[11].spr,
    game->new_game->character[11].pos);
    sfSprite_setScale(game->new_game->character[11].spr, (sfVector2f){8, 8});
    game->new_game->character[11].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[11].spr,
    game->new_game->character[11].rect);
    return (0);
}

int create_cop_blue(game_t *game)
{
    game->new_game->character[12].text = sfTexture_createFromFile
    ("assets/new_game/Cop_blue.png", NULL);
    game->new_game->character[12].spr = sfSprite_create();
    if (game->new_game->character[12].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[12].spr,
    game->new_game->character[12].text, sfTrue);
    game->new_game->character[12].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[12].spr,
    game->new_game->character[12].pos);
    sfSprite_setScale(game->new_game->character[12].spr, (sfVector2f){8, 8});
    game->new_game->character[12].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[12].spr,
    game->new_game->character[12].rect);
    return (0);
}

int create_cop_green(game_t *game)
{
    game->new_game->character[13].text = sfTexture_createFromFile
    ("assets/new_game/Cop_green.png", NULL);
    game->new_game->character[13].spr = sfSprite_create();
    if (game->new_game->character[13].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[13].spr,
    game->new_game->character[13].text, sfTrue);
    game->new_game->character[13].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[13].spr,
    game->new_game->character[13].pos);
    sfSprite_setScale(game->new_game->character[13].spr, (sfVector2f){8, 8});
    game->new_game->character[13].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[13].spr,
    game->new_game->character[13].rect);
    return (0);
}

int create_cop_pink(game_t *game)
{
    game->new_game->character[14].text = sfTexture_createFromFile
    ("assets/new_game/Cop_pink.png", NULL);
    game->new_game->character[14].spr = sfSprite_create();
    if (game->new_game->character[14].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[14].spr,
    game->new_game->character[14].text, sfTrue);
    game->new_game->character[14].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[14].spr,
    game->new_game->character[14].pos);
    sfSprite_setScale(game->new_game->character[14].spr, (sfVector2f){8, 8});
    game->new_game->character[14].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[14].spr,
    game->new_game->character[14].rect);
    return (0);
}
