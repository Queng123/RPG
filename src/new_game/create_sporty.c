/*
** EPITECH PROJECT, 2022
** create_character_sporty.c
** File description:
** file with all function that create sporty and differents colors
*/

#include "rpg.h"

int create_sporty_basic(game_t *game)
{
    game->new_game->character[5].text = sfTexture_createFromFile
    ("assets/new_game/Sporty_basic.png", NULL);
    game->new_game->character[5].spr = sfSprite_create();
    if (game->new_game->character[5].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[5].spr,
    game->new_game->character[5].text, sfTrue);
    game->new_game->character[5].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[5].spr,
    game->new_game->character[5].pos);
    sfSprite_setScale(game->new_game->character[5].spr, (sfVector2f){8, 8});
    game->new_game->character[5].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[5].spr,
    game->new_game->character[5].rect);
    return (0);
}

int create_sporty_red(game_t *game)
{
    game->new_game->character[6].text = sfTexture_createFromFile
    ("assets/new_game/Sporty_red.png", NULL);
    game->new_game->character[6].spr = sfSprite_create();
    if (game->new_game->character[6].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[6].spr,
    game->new_game->character[6].text, sfTrue);
    game->new_game->character[6].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[6].spr,
    game->new_game->character[6].pos);
    sfSprite_setScale(game->new_game->character[6].spr, (sfVector2f){8, 8});
    game->new_game->character[6].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[6].spr,
    game->new_game->character[6].rect);
    return (0);
}

int create_sporty_blue(game_t *game)
{
    game->new_game->character[7].text = sfTexture_createFromFile
    ("assets/new_game/Sporty_blue.png", NULL);
    game->new_game->character[7].spr = sfSprite_create();
    if (game->new_game->character[7].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[7].spr,
    game->new_game->character[7].text, sfTrue);
    game->new_game->character[7].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[7].spr,
    game->new_game->character[7].pos);
    sfSprite_setScale(game->new_game->character[7].spr, (sfVector2f){8, 8});
    game->new_game->character[7].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[7].spr,
    game->new_game->character[7].rect);
    return (0);
}

int create_sporty_green(game_t *game)
{
    game->new_game->character[8].text = sfTexture_createFromFile
    ("assets/new_game/Sporty_green.png", NULL);
    game->new_game->character[8].spr = sfSprite_create();
    if (game->new_game->character[8].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[8].spr,
    game->new_game->character[8].text, sfTrue);
    game->new_game->character[8].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[8].spr,
    game->new_game->character[8].pos);
    sfSprite_setScale(game->new_game->character[8].spr, (sfVector2f){8, 8});
    game->new_game->character[8].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[8].spr,
    game->new_game->character[8].rect);
    return (0);
}

int create_sporty_pink(game_t *game)
{
    game->new_game->character[9].text = sfTexture_createFromFile
    ("assets/new_game/Sporty_pink.png", NULL);
    game->new_game->character[9].spr = sfSprite_create();
    if (game->new_game->character[9].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[9].spr,
    game->new_game->character[9].text, sfTrue);
    game->new_game->character[9].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[9].spr,
    game->new_game->character[9].pos);
    sfSprite_setScale(game->new_game->character[9].spr, (sfVector2f){8, 8});
    game->new_game->character[9].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[9].spr,
    game->new_game->character[9].rect);
    return (0);
}
