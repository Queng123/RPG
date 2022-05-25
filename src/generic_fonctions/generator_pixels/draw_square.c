/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void draw_square(game_t *game, pixel_t *pixel_s, sfVector2u center,
sfVector2f tail)
{
    int y = tail.y;
    int x = tail.x;

    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            selected_color_pixel(pixel_s, (center.x + j), (center.y + i));
        }
    }
    draw_pixel(game, pixel_s);
}
