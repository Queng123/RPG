/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void draw_sprite_frame_seven(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[15]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[19]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[20]->sprite, NULL);
}

void draw_bubulle_legende_six(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[15]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[16]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[4]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[1]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->intro_s->background[20]->sprite, NULL);
}

void draw_frame_seven(game_t *game)
{
    sfVector2f pos_mouse = rcp_mouse(game->event.mouseButton);

    if (game->intro_s->frame_one == 7) {
        draw_sprite_frame_seven(game);
        if (check_is_click_ok(game, (sfVector2f){1707, 959},
        (sfVector2f){1854, 991}, pos_mouse) == 1)
            game->intro_s->bubulle_legende = 6;
        if (game->intro_s->bubulle_legende == 6) {
            draw_bubulle_legende_six(game);
        }
        if (game->intro_s->bubulle_legende == 6 &&
        check_is_click_ok(game, (sfVector2f){39, 957},
        (sfVector2f){227, 1005}, pos_mouse) == 1)
            game->intro_s->frame_one = 8;
    }
}
