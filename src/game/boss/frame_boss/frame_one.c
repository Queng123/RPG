/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void display_frame_one(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[6]->sprite, NULL);
    sfSprite_setPosition(game->boss_s->background[5]->sprite,
    (sfVector2f){800, 640});
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[5]->sprite, NULL);
}

void frame_one(game_t *game)
{
    sfVector2f pos_mouse = rcp_mouse(game->event.mouseButton);

    if (game->boss_s->frame_boss == 1) {
        display_frame_one(game);
        if (game->boss_s->frame_boss == 1 &&
        check_is_click_ok(game, (sfVector2f){800, 640},
        (sfVector2f){1138, 767}, pos_mouse) == 1) {
            game->boss_s->frame_boss = 2;
            game->boss_s->key_rand = rand() % 26;
            game->boss_s->clock_s->seconds = 0;
            game->boss_s->fight = true;
        }
    }
}
