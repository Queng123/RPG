/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void move_animation_intro(game_t *game)
{
    float second_p = 1;
    game->intro_s->time = sfClock_getElapsedTime(game->intro_s->clock);
    game->intro_s->sec = game->intro_s->time.microseconds / 1000000.0;
    sfClock_restart(game->intro_s->clock);
    game->intro_s->rect.left -= game->intro_s->sec / second_p * 100;
    sfSprite_setTextureRect(game->intro_s->background[20]->sprite,
    game->intro_s->rect);
}

void handling_frame(game_t *game, sfVector2f pos_mouse)
{
    check_condition_frame_actif(game, pos_mouse);
    draw_frame_zero(game);
    draw_frame_one(game);
    move_animation_intro(game);
    draw_frame_two(game);
    draw_frame_three(game);
    draw_frame_four(game);
    draw_frame_five(game);
    draw_frame_six(game);
    draw_frame_seven(game);
    draw_frame_eight(game);
}
