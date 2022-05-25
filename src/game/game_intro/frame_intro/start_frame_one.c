/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void draw_sprite_frame_one(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[2]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[3]->sprite, NULL);
}

void draw_sprite_and_settings_cinema(game_t *game)
{
    game->pixel_s->sl_color = 4;
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[4]->sprite, NULL);
    draw_square(game, game->pixel_s, (sfVector2u){0, 0},
    (sfVector2f){1080, 1920});
}

void start_frame_one(game_t *game)
{
    sfVector2f pos_mouse = rcp_mouse(game->event.mouseButton);

    draw_sprite_frame_one(game);
    game->pixel_s->sl_color = 3;
    draw_square(game, game->pixel_s, (sfVector2u){452, 106},
    (sfVector2f){576, 1176});
    if (game->intro_s->cinema == 1) {
        draw_sprite_and_settings_cinema(game);
        if (check_is_click_ok(game, (sfVector2f){39, 957},
        (sfVector2f){227, 1005}, pos_mouse) == 1)
            game->intro_s->frame_one = 2;
    }
}
