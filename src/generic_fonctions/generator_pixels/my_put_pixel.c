/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void my_put_pixel(pixel_t *pixel_s, unsigned int x, unsigned int y,
sfColor *color)
{
    pixel_s->pix[(x + pixel_s->width * y) * 4] = color->r;
    pixel_s->pix[(x + pixel_s->width * y) * 4 + 1] = color->g;
    pixel_s->pix[(x + pixel_s->width * y) * 4 + 2] = color->b;
    pixel_s->pix[(x + pixel_s->width * y) * 4 + 3] = color->a;
}
