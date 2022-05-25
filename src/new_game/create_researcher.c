/*
** EPITECH PROJECT, 2022
** create_character_researcher.c
** File description:
** file with all function that create researcher and differents colors
*/

#include "rpg.h"

int create_researcher_basic(game_t *game)
{
    game->new_game->character[15].text = sfTexture_createFromFile
    ("assets/new_game/Researcher_basic.png", NULL);
    game->new_game->character[15].spr = sfSprite_create();
    if (game->new_game->character[15].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[15].spr,
    game->new_game->character[15].text, sfTrue);
    game->new_game->character[15].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[15].spr,
    game->new_game->character[15].pos);
    sfSprite_setScale(game->new_game->character[15].spr, (sfVector2f){8, 8});
    game->new_game->character[15].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[15].spr,
    game->new_game->character[15].rect);
    return (0);
}

int create_researcher_red(game_t *game)
{
    game->new_game->character[16].text = sfTexture_createFromFile
    ("assets/new_game/Researcher_red.png", NULL);
    game->new_game->character[16].spr = sfSprite_create();
    if (game->new_game->character[16].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[16].spr,
    game->new_game->character[16].text, sfTrue);
    game->new_game->character[16].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[16].spr,
    game->new_game->character[16].pos);
    sfSprite_setScale(game->new_game->character[16].spr, (sfVector2f){8, 8});
    game->new_game->character[16].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[16].spr,
    game->new_game->character[16].rect);
    return (0);
}

int create_researcher_blue(game_t *game)
{
    game->new_game->character[17].text = sfTexture_createFromFile
    ("assets/new_game/Researcher_blue.png", NULL);
    game->new_game->character[17].spr = sfSprite_create();
    if (game->new_game->character[17].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[17].spr,
    game->new_game->character[17].text, sfTrue);
    game->new_game->character[17].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[17].spr,
    game->new_game->character[17].pos);
    sfSprite_setScale(game->new_game->character[17].spr, (sfVector2f){8, 8});
    game->new_game->character[17].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[17].spr,
    game->new_game->character[17].rect);
    return (0);
}

int create_researcher_green(game_t *game)
{
    game->new_game->character[18].text = sfTexture_createFromFile
    ("assets/new_game/Researcher_green.png", NULL);
    game->new_game->character[18].spr = sfSprite_create();
    if (game->new_game->character[18].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[18].spr,
    game->new_game->character[18].text, sfTrue);
    game->new_game->character[18].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[18].spr,
    game->new_game->character[18].pos);
    sfSprite_setScale(game->new_game->character[18].spr, (sfVector2f){8, 8});
    game->new_game->character[18].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[18].spr,
    game->new_game->character[18].rect);
    return (0);
}

int create_researcher_pink(game_t *game)
{
    game->new_game->character[19].text = sfTexture_createFromFile
    ("assets/new_game/Researcher_pink.png", NULL);
    game->new_game->character[19].spr = sfSprite_create();
    if (game->new_game->character[19].spr == NULL)
        return (84);
    sfSprite_setTexture(game->new_game->character[19].spr,
    game->new_game->character[19].text, sfTrue);
    game->new_game->character[19].pos = (sfVector2f){580, 330};
    sfSprite_setPosition(game->new_game->character[19].spr,
    game->new_game->character[19].pos);
    sfSprite_setScale(game->new_game->character[19].spr, (sfVector2f){8, 8});
    game->new_game->character[19].rect = (sfIntRect){30, 0, 30, 32};
    sfSprite_setTextureRect(game->new_game->character[19].spr,
    game->new_game->character[19].rect);
    return (0);
}
