/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** make_animation
*/

#include "particles.h"

void create_bounce(pixel_t *pixel_s, sfVector2f center, int radius,
sfColor color)
{
    int pt = 0;
    int temp_i = center.y - radius;
    int temp_j = center.x - radius;

    for (int i = temp_i; i <= (2 * radius) + temp_i; i++) {
        for (int j = temp_j; j <= (2 * radius) + temp_j; j++) {
            pt = (j - center.x) * (j - center.x) + (i - center.y) * \
            (i - center.y);
            if (pt <= radius * radius)
                my_put_pixel(pixel_s, i, j, &color);
        }
    }
}

sfUint8 check_green(sfColor actual, sfColor start, sfColor end,
float ratio)
{
    float abs_g = abs(start.g - end.g);

    if (start.g > end.g)
        actual.g = start.g + (abs_g * ratio);
    else
        actual.g = start.g - (abs_g * ratio);
    return (actual.g);
}

sfColor change_color_and_fade(sfColor actual, sfColor start, sfColor end,
float ratio)
{
    float abs_r = abs(start.r - end.r);
    float abs_b = abs(start.b - end.b);

    if (actual.a < 230)
        actual.a = 255 * ratio;
    if (start.r > end.r)
        actual.r = start.r + (abs_r * ratio);
    else
        actual.r = start.r - (abs_r * ratio);
    actual.g = check_green(actual, start, end, ratio);
    if (start.b > end.b)
        actual.b = start.b + (abs_b * ratio);
    else
        actual.b = start.b - (abs_b * ratio);
    return (actual);
}
