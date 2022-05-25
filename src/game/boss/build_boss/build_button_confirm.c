/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void build_button_confirm(boss_t *boss_s, int i)
{
    char *menu = "assets/intro/arrow_right.png";

    boss_s->background[i] = malloc(sizeof(sprite_t));
    boss_s->background[i]->scale = (sfVector2f) {1.5, 1.5};
    boss_s->background[i]->pos = (sfVector2f) {800, 876};
    boss_s->background[i]->sprite = sfSprite_create();
    boss_s->background[i]->texture = sfTexture_createFromFile(menu, NULL);
    if (boss_s->background[i] == NULL || boss_s->background[i]->sprite == NULL
    || boss_s->background[i]->texture == NULL)
        boss_s->error = 1;
    sfSprite_setTexture(boss_s->background[i]->sprite,
    boss_s->background[i]->texture, sfTrue);
    sfSprite_setScale(boss_s->background[i]->sprite,
    boss_s->background[i]->scale);
    sfSprite_setPosition(boss_s->background[i]->sprite,
    boss_s->background[i]->pos);
    boss_s->background[i]->sprite = boss_s->background[i]->sprite;
}
