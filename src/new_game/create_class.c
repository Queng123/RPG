/*
** EPITECH PROJECT, 2022
** create_class.c
** File description:
** file with all function that create class of the game
*/

#include "rpg.h"

int create_class_soldier(game_t *game)
{
    game->new_game->class_menu[0].text = sfTexture_createFromFile
    ("assets/new_game/Soldier.png", NULL);
    game->new_game->class_menu[0].spr = sfSprite_create();
    if (game->new_game->class_menu[0].spr == NULL)
        return (84);
    game->new_game->class_menu[0].pos = (sfVector2f){375, 182};
    sfSprite_setPosition(game->new_game->class_menu[0].spr,
    game->new_game->class_menu[0].pos);
    sfSprite_setTexture(game->new_game->class_menu[0].spr,
    game->new_game->class_menu[0].text, sfTrue);
    return (0);
}

int create_class_sporty(game_t *game)
{
    game->new_game->class_menu[1].text = sfTexture_createFromFile
    ("assets/new_game/Sporty.png", NULL);
    game->new_game->class_menu[1].spr = sfSprite_create();
    if (game->new_game->class_menu[0].spr == NULL)
        return (84);
    game->new_game->class_menu[1].pos = (sfVector2f){375, 182};
    sfSprite_setPosition(game->new_game->class_menu[1].spr,
    game->new_game->class_menu[1].pos);
    sfSprite_setTexture(game->new_game->class_menu[1].spr,
    game->new_game->class_menu[1].text, sfTrue);
    return (0);
}

int create_class_cop(game_t *game)
{
    game->new_game->class_menu[2].text = sfTexture_createFromFile
    ("assets/new_game/Cop.png", NULL);
    game->new_game->class_menu[2].spr = sfSprite_create();
    if (game->new_game->class_menu[2].spr == NULL)
        return (84);
    game->new_game->class_menu[2].pos = (sfVector2f){375, 182};
    sfSprite_setPosition(game->new_game->class_menu[2].spr,
    game->new_game->class_menu[2].pos);
    sfSprite_setTexture(game->new_game->class_menu[2].spr,
    game->new_game->class_menu[2].text, sfTrue);
    return (0);
}

int create_class_researcher(game_t *game)
{
    game->new_game->class_menu[3].text = sfTexture_createFromFile
    ("assets/new_game/Researcher.png", NULL);
    game->new_game->class_menu[3].spr = sfSprite_create();
    if (game->new_game->class_menu[3].spr == NULL)
        return (84);
    game->new_game->class_menu[3].pos = (sfVector2f){375, 182};
    sfSprite_setPosition(game->new_game->class_menu[3].spr,
    game->new_game->class_menu[3].pos);
    sfSprite_setTexture(game->new_game->class_menu[3].spr,
    game->new_game->class_menu[3].text, sfTrue);
    return (0);
}

int create_class(game_t *game)
{
    if (create_class_soldier(game) == 84)
        return (84);
    if (create_class_cop(game) == 84)
        return (84);
    if (create_class_researcher(game) == 84)
        return (84);
    if (create_class_sporty(game) == 84)
        return (84);
    return (0);
}
