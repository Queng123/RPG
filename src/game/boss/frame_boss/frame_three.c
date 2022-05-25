/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void display_frame_three(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[11]->sprite, NULL);
}

void display_msg_boss_zero(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[12]->sprite, NULL);
    game->boss_s->background[5]->pos = (sfVector2f) {0, 920};
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[5]->sprite, NULL);
}

void frame_three(game_t *game)
{
    sfVector2f pos_mouse = rcp_mouse(game->event.mouseButton);

    if (game->boss_s->frame_boss == 3) {
        display_frame_three(game);
        if (check_is_click_ok(game, (sfVector2f){1707, 959},
        (sfVector2f){1854, 991}, pos_mouse) == 1)
            game->boss_s->bubulle_legende = 1;
        if (game->boss_s->bubulle_legende == 1) {
            display_msg_boss_zero(game);
        }
        if (game->boss_s->bubulle_legende == 1
        && check_is_click_ok(game, (sfVector2f){854, 688},
        (sfVector2f){1137, 762}, pos_mouse) == 1)
            game->boss_s->frame_boss = 4;
    }
}
