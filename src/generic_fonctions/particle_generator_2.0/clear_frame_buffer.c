/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** clear_frame_buffer
*/

#include "struct.h"
#include "particles.h"

pixel_t *clear_framebuffer(pixel_t *framebuffer, int x, int y, sfColor *color)
{
    for (int i = 0; i != x; i++) {
        for (int j = 0; j != y; j++) {
            my_put_pixel(framebuffer, i, j, color);
        }
    }
    return (framebuffer);
}
