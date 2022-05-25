/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void build_bar_info(intro_t *intro_s, int i)
{
    char *menu = "assets/intro/bar_info.png";

    intro_s->background[i] = malloc(sizeof(sprite_t));
    intro_s->background[i]->scale = (sfVector2f) {1, 1};
    intro_s->background[i]->pos = (sfVector2f) {0, 0};
    intro_s->background[i]->sprite = sfSprite_create();
    intro_s->background[i]->texture = sfTexture_createFromFile(menu, NULL);
    if (intro_s->background[i] == NULL || intro_s->background[i]->sprite == NULL
    || intro_s->background[i]->texture == NULL)
        intro_s->error = 1;
    sfSprite_setTexture(intro_s->background[i]->sprite,
    intro_s->background[i]->texture, sfTrue);
    sfSprite_setScale(intro_s->background[i]->sprite,
    intro_s->background[i]->scale);
    sfSprite_setPosition(intro_s->background[i]->sprite,
    intro_s->background[i]->pos);
    sfTexture_setRepeated(intro_s->background[20]->texture, sfTrue);
    intro_s->sec = 0;
    intro_s->rect = (sfIntRect){0, 0, 1920, 56};
    intro_s->background[i]->sprite = intro_s->background[i]->sprite;
}
