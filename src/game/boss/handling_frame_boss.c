/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** current_item
*/

#include "rpg.h"

void init_sprite_player(game_t *game)
{
    sfSprite_setScale(game->player->obj->sprite,
    (sfVector2f){12, 12});
    sfSprite_setPosition(game->player->obj->sprite, (sfVector2f){300, 600});
}

void draw_animation_boss(game_t *game)
{
    while (game->boss_s->ck_boss->seconds >= 1) {
        game->boss_s->ck_boss->seconds -= 1;
        game->boss_s->background[1]->rect.left += 64;
        if (game->boss_s->background[1]->rect.left >= 192)
            game->boss_s->background[1]->rect.left = 0;
    }
    restart_clock_boss_animation(game);
    sfSprite_setTextureRect(game->boss_s->background[1]->sprite,
    game->boss_s->background[1]->rect);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[1]->sprite, NULL);
}

void handling_frame_boss(game_t *game)
{
    init_sprite_player(game);
    frame_zero(game);
    frame_one(game);
    frame_two(game);
    frame_three(game);
    frame_four(game);
    frame_five(game);
    if (game->boss_s->frame_boss == 2) {
        display_systeme_qte(game);
    }
    if (game->boss_s->frame_boss != 6)
        draw_animation_boss(game);
}
