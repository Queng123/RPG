/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_bg
*/

#include "rpg.h"

void display_bg(sprite_t *bg, sfRenderWindow *win)
{
    sfSprite_setPosition(bg->sprite, bg->pos);
    sfSprite_setScale(bg->sprite, bg->scale);
    sfRenderWindow_drawSprite(win, bg->sprite, NULL);
}
