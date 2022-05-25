/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

sfVector2f rcp_mouse(sfMouseButtonEvent mouse)
{
    sfVector2f pos_mouse = {mouse.x, mouse.y};
    return (pos_mouse);

}

int check_is_click_ok(game_t *game_s, sfVector2f pos_to_check,
sfVector2f pos_ref, sfVector2f pos_mouse)
{
    if (game_s->event.type == sfEvtMouseButtonPressed) {
        if (pos_mouse.x >= (pos_to_check.x) && pos_mouse.x <= (pos_ref.x)
        && pos_mouse.y >= (pos_to_check.y) && pos_mouse.y <= (pos_ref.y))
            return (1);
    }
    return (0);
}
