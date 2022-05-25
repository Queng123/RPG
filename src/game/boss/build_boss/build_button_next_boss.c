/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void build_button_next_boss(boss_t *boss_s, int i)
{
    char *menu = "assets/intro/button_next.png";

    boss_s->background[i] = malloc(sizeof(sprite_t));
    boss_s->background[i]->scale = (sfVector2f) {0.5, 0.5};
    boss_s->background[i]->pos = (sfVector2f) {1700, 950};
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
