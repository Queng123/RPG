/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

void build_bubulle_leg(game_t *game_s)
{
    build_bubulle_leg_one(game_s->intro_s, 6);
    build_bubulle_leg_two(game_s->intro_s, 8);
    build_bubulle_leg_three(game_s->intro_s, 10);
    build_bubulle_leg_four(game_s->intro_s, 12);
    build_bubulle_leg_five(game_s->intro_s, 14);
    build_bubulle_leg_six(game_s->intro_s, 16);
}

void build_all_intro(game_t *game_s)
{
    build_intro(game_s->intro_s, 0);
    build_bubulle_leg(game_s);
    build_button_skip(game_s->intro_s, 1);
    build_frame_one(game_s->intro_s, 2);
    build_clap_board(game_s->intro_s, 3);
    build_arrow_right(game_s->intro_s, 4);
    build_search_job(game_s->intro_s, 5);
    build_last_mission(game_s->intro_s, 7);
    build_boss_zombie(game_s->intro_s, 9);
    build_invasion_zombie(game_s->intro_s, 11);
    build_post_world(game_s->intro_s, 13);
    build_save_sister(game_s->intro_s, 15);
    build_last_mission_player(game_s->intro_s, 17);
    build_play_game(game_s->intro_s, 18);
    build_button_next(game_s->intro_s, 19);
    build_bar_info(game_s->intro_s, 20);
}

int init_pixel_s(game_t *game_s)
{
    game_s->pixel_s = pixel_s_create(1920, 1080);
    game_s->pixel_s->texture = sfTexture_create(1920, 1080);
    game_s->pixel_s->sprite = sfSprite_create();
    game_s->pixel_s->sl_color = 0;
    return (0);
}

int init_struct_intro(game_t *game_s)
{
    game_s->intro_s = malloc(sizeof(intro_t));
    game_s->intro_s->frame_one = 0;
    game_s->intro_s->cinema = 0;
    game_s->intro_s->bubulle_legende = 0;
    game_s->intro_s->clock = sfClock_create();
    game_s->intro_s->sec = 0;
    game_s->intro_s->error = 0;
    return (0);
}

int init_intro(game_t *game_s)
{
    init_pixel_s(game_s);
    init_struct_intro(game_s);

    if (game_s->intro_s == NULL || game_s->intro_s->background == NULL
    || game_s->intro_s->clock == NULL)
        return (ERROR);
    build_all_intro(game_s);
    if (game_s->intro_s->error == 1)
        return (ERROR);
    return (SUCCESS);
}
