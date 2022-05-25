/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_button
*/

#include "rpg.h"

void display_button(button_t *button, sfRenderWindow *window)
{
    if (button->sprite->sprite != NULL) {
        sfSprite_setPosition(button->sprite->sprite,
        button->sprite->pos);
        sfSprite_setScale(button->sprite->sprite,
        button->sprite->scale);
        sfRenderWindow_drawSprite(window,
        button->sprite->sprite, NULL);
    }
    if (button->text->text != NULL) {
        sfText_setPosition(button->text->text, button->text->pos);
        sfText_setScale(button->text->text, button->text->scale);
        sfText_setString(button->text->text, button->text->str);
        sfRenderWindow_drawText(window, button->text->text, NULL);
    }
}
