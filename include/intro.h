/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game
*/

#ifndef INTRO_H
    #define INTRO_H

/******************************include*****************************************/

    #include "struct.h"

/******************************fonctions***************************************/

void display_intro(game_t *game);
int init_intro(game_t *game_s);
sfVector2f rcp_mouse(sfMouseButtonEvent mouse);
int check_is_click_ok(game_t *game_s, sfVector2f pos_to_check,
sfVector2f pos_ref, sfVector2f pos_mouse);
void handling_frame(game_t *game, sfVector2f pos_mouse);
void draw_frame_one(game_t *game);
void draw_frame_zero(game_t *game);
void start_frame_one(game_t *game);
void check_condition_frame_actif(game_t *game, sfVector2f pos_mouse);
void draw_frame_two(game_t *game);
void draw_frame_three(game_t *game);
void draw_frame_four(game_t *game);
void draw_frame_five(game_t *game);
void draw_frame_six(game_t *game);
void draw_frame_seven(game_t *game);
void draw_frame_eight(game_t *game);
void build_search_job(intro_t *intro_s, int i);
void build_save_sister(intro_t *intro_s, int i);
void build_post_world(intro_t *intro_s, int i);
void build_play_game(intro_t *intro_s, int i);
void build_last_mission(intro_t *intro_s, int i);
void build_last_mission_player(intro_t *intro_s, int i);
void build_invasion_zombie(intro_t *intro_s, int i);
void build_intro(intro_t *intro_s, int i);
void build_frame_one(intro_t *intro_s, int i);
void build_clap_board(intro_t *intro_s, int i);
void build_button_skip(intro_t *intro_s, int i);
void build_bubulle_leg_two(intro_t *intro_s, int i);
void build_bubulle_leg_three(intro_t *intro_s, int i);
void build_bubulle_leg_one(intro_t *intro_s, int i);
void build_bubulle_leg_four(intro_t *intro_s, int i);
void build_bubulle_leg_five(intro_t *intro_s, int i);
void build_bubulle_leg_six(intro_t *intro_s, int i);
void build_boss_zombie(intro_t *intro_s, int i);
void build_arrow_right(intro_t *intro_s, int i);
void build_button_next(intro_t *intro_s, int i);
void build_bar_info(intro_t *intro_s, int i);

#endif/* !INTRO_H */
