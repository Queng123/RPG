/*
** EPITECH PROJECT, 2022
** lol
** File description:
** build_obj_function
*/

#include "gameplay.h"
#include "build.h"

void build_obj_set_sprite_and_texture(obj_t *obj,
sfSprite *sprite, sfTexture *texture, state_t state)
{
    obj->texture = texture;
    obj->sprite = sprite;
    obj->state_s = state;
}

obj_t *build_obj(char *filepath, sfIntRect rect, state_t state, type_t type)
{
    obj_t *obj = malloc(sizeof(obj_t));
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);
    if (obj == NULL || sprite == NULL || texture == NULL)
        return (NULL);
    sfTexture_setRepeated(texture, sfTrue);
    sfSprite_setTexture(sprite, texture, sfTrue);
    sfSprite_setTextureRect(sprite, rect);
    obj->inertia = (sfVector2f) {0, 0};
    obj->pos = (sfVector2f){1014, 564};
    obj->rect = rect;
    obj->scale = (sfVector2f) {1, 1};
    build_obj_set_sprite_and_texture(obj, sprite, texture, state);
    obj->abs = 0.5;
    obj->type = type;
    obj->hp = 100;
    obj->clock_sprite = build_clock();
    obj->clock_attack = build_clock();
    obj->clock_move = build_clock();
    return (obj);
}
