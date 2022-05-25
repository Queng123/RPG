/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void check_condition_frame_actif(game_t *game, sfVector2f pos_mouse)
{
    if (check_is_click_ok(game, (sfVector2f){351, 686},
    (sfVector2f){436, 745}, pos_mouse) == 1
    || check_is_click_ok(game, (sfVector2f){512, 312},
    (sfVector2f){709, 545}, pos_mouse) == 1)
        game->intro_s->frame_one = 1;
}
