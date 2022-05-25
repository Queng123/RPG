/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void draw_pixel(game_t *game, pixel_t *pixel_s)
{
    sfSprite_setTexture(pixel_s->sprite, pixel_s->texture, sfTrue);
    sfTexture_updateFromPixels(pixel_s->texture, pixel_s->pix,
    1920, 1080, 0, 0);
    sfRenderWindow_drawSprite(game->game_info->window, pixel_s->sprite, NULL);
}
