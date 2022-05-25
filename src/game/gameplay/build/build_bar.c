/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_bar
*/

#include "gameplay.h"

sprite_t *build_sprit(sfIntRect rect, const char *filepath, sfVector2f scale,
sfVector2f pos)
{
    sprite_t *sprite_s = malloc(sizeof(sprite_t));
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    if (sprite_s == NULL || sprite == NULL || texture == NULL) {
        return (NULL);
    }
    sfTexture_setRepeated(texture, sfTrue);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    sfSprite_setScale(sprite, scale);
    sprite_s->rect = rect;
    sprite_s->pos = pos;
    sprite_s->scale = scale;
    sprite_s->sprite = sprite;
    sprite_s->texture = texture;
    return (sprite_s);
}

bar_t *build_bar(char *filepath, int max, sfIntRect rect, sfVector2f pos)
{
    bar_t *bar = malloc(sizeof(bar_t));

    if (bar == NULL) {
        return (NULL);
    }
    bar->info = build_sprit(rect, filepath, (sfVector2f) {1.5, 1}, pos);
    if (bar->info == NULL) {
        return (NULL);
    }
    bar->current_score = max;
    bar->max_score = max;
    return (bar);
}
