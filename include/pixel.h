/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game
*/

#ifndef PIXEL_H
    #define PIXEL_H

/******************************include*****************************************/

    #include "struct.h"

/******************************fonctions***************************************/

pixel_t *pixel_s_create(unsigned int width, unsigned int height);
void draw_square(game_t *game, pixel_t *pixel_s, sfVector2u center,
sfVector2f tail);
void selected_color_pixel(pixel_t *pixel_s, unsigned int x, unsigned int y);
void draw_pixel(game_t *game, pixel_t *pixel_s);
void my_put_pixel(pixel_t *pixel_s, unsigned int x, unsigned int y,
sfColor *color);

#endif/* !PIXEL_H */
