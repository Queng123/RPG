/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_bg
*/

#include "rpg.h"

sprite_t *build_bg(char *filepath)
{
    sprite_t *background = malloc(sizeof(sprite_t));

    if (background == NULL)
        return (NULL);
    background->texture = sfTexture_createFromFile(filepath, NULL);
    if (background->texture == NULL)
        return (NULL);
    background->sprite = sfSprite_create();
    if (background->sprite == NULL)
        return (NULL);
    sfSprite_setTexture(background->sprite, background->texture, sfTrue);
    return (background);
}
