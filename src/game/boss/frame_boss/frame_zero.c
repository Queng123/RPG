/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void display_frame_zero(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[4]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[5]->sprite, NULL);
}

void frame_zero(game_t *game)
{
    sfVector2f pos_mouse = rcp_mouse(game->event.mouseButton);

    if (game->boss_s->frame_boss == 0) {
        display_frame_zero(game);
        if (game->boss_s->frame_boss == 0 &&
        check_is_click_ok(game, (sfVector2f){856, 926},
        (sfVector2f){1138, 1003}, pos_mouse) == 1)
            game->boss_s->frame_boss = 1;
    }
}
