/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void draw_frame_one(game_t *game)
{
    sfVector2f pos_mouse = rcp_mouse(game->event.mouseButton);

    if (game->intro_s->frame_one == 1) {
        if (check_is_click_ok(game, (sfVector2f){1011, 690},
        (sfVector2f){1062, 732}, pos_mouse) == 1)
            game->intro_s->cinema = 1;
        start_frame_one(game);
    }
}
