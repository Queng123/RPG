/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void build_st_five(howtwoplay_t *howtwoplay_s, int i)
{
    char *menu = "assets/how2play/Quest.jpg";

    howtwoplay_s->background[i] = malloc(sizeof(sprite_t));
    howtwoplay_s->background[i]->scale = (sfVector2f) {1.3 / 2, 1.3 / 2};
    howtwoplay_s->background[i]->pos = (sfVector2f) {375, 257};
    howtwoplay_s->background[i]->sprite = sfSprite_create();
    howtwoplay_s->background[i]->texture = sfTexture_createFromFile(menu, NULL);
    if (howtwoplay_s->background[i] == NULL
        || howtwoplay_s->background[i]->sprite == NULL
        || howtwoplay_s->background[i]->texture == NULL)
        howtwoplay_s->error = 1;
    sfSprite_setTexture(howtwoplay_s->background[i]->sprite,
    howtwoplay_s->background[i]->texture, sfTrue);
    sfSprite_setScale(howtwoplay_s->background[i]->sprite,
    howtwoplay_s->background[i]->scale);
    sfSprite_setPosition(howtwoplay_s->background[i]->sprite,
    howtwoplay_s->background[i]->pos);
    howtwoplay_s->background[i]->sprite = howtwoplay_s->background[i]->sprite;
}
