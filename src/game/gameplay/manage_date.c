/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** manage_clock
*/

#include "rpg.h"

void change_hours(button_t *button, sfRenderWindow *window, int h)
{
    button->text->pos = (sfVector2f) {30, 50};
    sfText_setPosition(button->text->text, button->text->pos);
    sfText_setScale(button->text->text, button->text->scale);
    sfText_setString(button->text->text, "DAY");
    sfRenderWindow_drawText(window, button->text->text, NULL);
    button->text->pos = (sfVector2f) {90, 50};
    sfText_setPosition(button->text->text, button->text->pos);
    sfText_setString(button->text->text, int_to_char(h));
    sfRenderWindow_drawText(window, button->text->text, NULL);
}

void change_minutes(button_t *button, sfRenderWindow *window, int m)
{
    if (m < 10) {
        button->text->pos = (sfVector2f) {25, 100};
        sfText_setPosition(button->text->text, button->text->pos);
        sfText_setString(button->text->text, "0");
        sfRenderWindow_drawText(window, button->text->text, NULL);
    }
    button->text->pos = (sfVector2f) {45, 100};
    if (m >= 10)
        button->text->pos = (sfVector2f) {25, 100};
    sfText_setPosition(button->text->text, button->text->pos);
    sfText_setString(button->text->text, int_to_char(m));
    sfRenderWindow_drawText(window, button->text->text, NULL);
    button->text->pos = (sfVector2f) {60, 100};
}

void change_seconds(button_t *button, sfRenderWindow *window, int s)
{
    sfText_setPosition(button->text->text, button->text->pos);
    sfText_setString(button->text->text, ":");
    sfRenderWindow_drawText(window, button->text->text, NULL);
    if (s < 10) {
        button->text->pos = (sfVector2f) {80, 100};
        sfText_setPosition(button->text->text, button->text->pos);
        sfText_setString(button->text->text, "0");
        sfRenderWindow_drawText(window, button->text->text, NULL);
    }
    button->text->pos = (sfVector2f) {100, 100};
    if (s >= 10)
        button->text->pos = (sfVector2f) {80, 100};
    sfText_setPosition(button->text->text, button->text->pos);
    sfText_setString(button->text->text, int_to_char(s));
    sfRenderWindow_drawText(window, button->text->text, NULL);
}
