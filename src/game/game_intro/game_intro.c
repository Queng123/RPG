/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void display_intro(game_t *game)
{
    sfVector2f pos_mouse = rcp_mouse(game->event.mouseButton);

    handling_frame(game, pos_mouse);
    if (game->intro_s->frame_one != 1
    && (check_is_click_ok(game, (sfVector2f){1683, 135},
    (sfVector2f){1756, 194}, pos_mouse) == 1
    || check_is_click_ok(game, (sfVector2f){1756, 104},
    (sfVector2f){1827, 226}, pos_mouse) == 1)) {
        game->game_info->scene->actual_game_scene = GAMEPLAY;
    }
}
