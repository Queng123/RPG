/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

sfColor selected_color_glitchpop(sfColor color, int pos, pixel_t *pixel_s)
{
    if (pixel_s->sl_color == 3) {
        if (pos == 0)
            color = sfBlack;
        if (pos == 1)
            color = sfBlack;
        if (pos == 2)
            color = sfWhite;
        if (pos >= 3)
            color = sfWhite;
    }
    return (color);
}

sfColor selected_color_black(sfColor color, int pos, pixel_t *pixel_s)
{
    if (pixel_s->sl_color == 4) {
        if (pos == 0)
            color = (sfColor){0, 0, 0, 100};
        if (pos == 1)
            color = (sfColor){0, 0, 0, 100};
        if (pos == 2)
            color = (sfColor){0, 0, 0, 100};
        if (pos >= 3)
            color = (sfColor){0, 0, 0, 100};
    }
    return (color);
}

void selected_color_pixel(pixel_t *pixel_s, unsigned int x, unsigned int y)
{
    int pos = rand() % 4;
    sfColor color = sfBlack;

    color = selected_color_glitchpop(color, pos, pixel_s);
    color = selected_color_black(color, pos, pixel_s);
    my_put_pixel(pixel_s, x, y, &color);
}
