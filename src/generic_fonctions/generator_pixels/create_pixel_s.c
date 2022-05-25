/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

pixel_t *pixel_s_create(unsigned int width, unsigned int height)
{
    pixel_t *pixel_s = malloc(sizeof(pixel_t));
    int bitsPerPixels = 4 * 8;

    if (pixel_s) {
        pixel_s->width = width;
        pixel_s->height = height;
        pixel_s->pix = malloc(width * height * bitsPerPixels);
        pixel_s->texture = sfTexture_create(width, height);
        pixel_s->sprite = sfSprite_create();
    }
    return (pixel_s);
}
