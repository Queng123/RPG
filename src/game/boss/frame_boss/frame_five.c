/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void display_frame_five(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[11]->sprite, NULL);
}

void display_msg_boss_two(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[14]->sprite, NULL);
    game->boss_s->background[5]->pos = (sfVector2f) {0, 920};
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[5]->sprite, NULL);
}

void display_msg_boss_three(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[15]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[16]->sprite, NULL);
    sfSprite_setPosition(game->boss_s->background[5]->sprite,
    game->boss_s->background[5]->pos);
    game->boss_s->background[5]->pos = (sfVector2f) {0, 920};
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[5]->sprite, NULL);
}

void check_interaction_frame_five(game_t *game, sfVector2f pos_mouse)
{
    if (check_is_click_ok(game, (sfVector2f){1707, 959},
    (sfVector2f){1854, 991}, pos_mouse) == 1)
        game->boss_s->bubulle_legende = 3;
    if (game->boss_s->bubulle_legende == 3)
        display_msg_boss_two(game);
    if (game->boss_s->bubulle_legende == 3
    && check_is_click_ok(game, (sfVector2f){854, 688},
    (sfVector2f){1137, 762}, pos_mouse) == 1)
        game->boss_s->bubulle_legende = 4;
    if (game->boss_s->bubulle_legende == 4)
        display_msg_boss_three(game);
    if (game->boss_s->bubulle_legende == 4
    && check_is_click_ok(game, (sfVector2f){55, 967},
    (sfVector2f){340, 1021}, pos_mouse) == 1) {
        game->boss_s->bubulle_legende = 5;
        game->quest->current_level_quest += 1;
        game->boss_s->frame_boss = 6;
        game->game_info->scene->actual_game_scene = GAMEPLAY;
    }
}

void frame_five(game_t *game)
{
    sfVector2f pos_mouse = rcp_mouse(game->event.mouseButton);

    if (game->boss_s->frame_boss == 5) {
        display_frame_five(game);
        check_interaction_frame_five(game, pos_mouse);
    }
    if (game->boss_s->frame_boss == 6) {
        sfRenderWindow_drawSprite(game->game_info->window,
        game->boss_s->background[0]->sprite, NULL);
        sfRenderWindow_drawSprite(game->game_info->window,
        game->player->obj->sprite, NULL);
        sfRenderWindow_drawSprite(game->game_info->window,
        game->boss_s->background[15]->sprite, NULL);
        sfRenderWindow_drawSprite(game->game_info->window,
        game->boss_s->background[16]->sprite, NULL);
        sfRenderWindow_drawSprite(game->game_info->window,
        game->boss_s->background[5]->sprite, NULL);
        if (check_is_click_ok(game, (sfVector2f){55, 967},
        (sfVector2f){340, 1021}, pos_mouse) == 1)
            game->game_info->scene->actual_game_scene = GAMEPLAY;
    }
}
