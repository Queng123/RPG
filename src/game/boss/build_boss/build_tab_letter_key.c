/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void build_tab_letter_key(boss_t *boss_s, int i)
{
    char *menu = "assets/menu/keyboard.png";

    boss_s->background[i] = malloc(sizeof(sprite_t));
    boss_s->background[i]->scale = (sfVector2f) {1, 1};
    boss_s->background[i]->pos = (sfVector2f) {920, 340};
    boss_s->background[i]->sprite = sfSprite_create();
    boss_s->background[i]->texture = sfTexture_createFromFile(menu, NULL);
    boss_s->background[i]->rect = (sfIntRect){0, 0, 193, 157};
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
