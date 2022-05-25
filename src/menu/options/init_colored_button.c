/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_colored_button
*/

#include "rpg.h"

int init_reseau(game_t *game)
{
    game->menu->background[8] = malloc(sizeof(sprite_t));
    if (game->menu->background[8] == NULL)
        return (84);
    game->menu->background[8]->texture =
    sfTexture_createFromFile("assets/menu/reseau.jpg", NULL);
    if (game->menu->background[8]->texture == NULL)
        return (84);
    game->menu->background[8]->sprite = sfSprite_create();
    if (game->menu->background[8]->sprite == NULL)
        return (84);
    game->menu->background[8]->pos = (sfVector2f) {1478, 153};
    game->menu->background[8]->scale = (sfVector2f) {1.3, 1.3};
    game->menu->background[8]->rect = (sfIntRect) {0, 0, 24, 18};
    sfSprite_setTexture(game->menu->background[8]->sprite,
    game->menu->background[8]->texture, sfTrue);
    return (0);
}

int init_colored_button(game_t *game)
{
    game->menu->background[5] = malloc(sizeof(sprite_t));
    if (game->menu->background[5] == NULL)
        return (84);
    game->menu->background[5]->texture =
    sfTexture_createFromFile("assets/menu/colored_button.jpg", NULL);
    if (game->menu->background[5]->texture == NULL)
        return (84);
    game->menu->background[5]->sprite = sfSprite_create();
    if (game->menu->background[5]->sprite == NULL)
        return (84);
    game->menu->background[5]->pos = (sfVector2f) {1778, 520};
    game->menu->background[5]->scale = (sfVector2f) {1.3, 1.3};
    game->menu->background[5]->rect = (sfIntRect) {0, 0, 21, 12};
    sfSprite_setTexture(game->menu->background[5]->sprite,
    game->menu->background[5]->texture, sfTrue);
    return (0);
}
