/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game
*/

#ifndef BOSS_H
    #define BOSS_H

/******************************include*****************************************/

    #include "struct.h"

/******************************fonctions***************************************/

int init_boss(game_t *game);
void display_boss(game_t *game);
void build_ring(boss_t *boss_s, int i);
void display_boss(game_t *game);
void build_player_boss(boss_t *boss_s, int i);
void build_boss(boss_t *boss_s, int i);
void analyse_event_boss(game_t *game);
void analyse_control_key_boss_qte(sfKeyEvent event, game_t *game);
void build_tab_letter_key(boss_t *boss_s, int i);
void build_versus(boss_t *boss_s, int i);
void handling_frame_boss(game_t *game);
void frame_zero(game_t *game);
void build_button_confirm(boss_t *boss_s, int i);
void frame_one(game_t *game);
void build_howtoplay_boss(boss_t *boss_s, int i);
void frame_two(game_t *game);
void build_ouch(boss_t *boss_s, int i);
void build_paf(boss_t *boss_s, int i);
void display_ouch(game_t *game);
void display_paf(game_t *game);
void build_heart_player(boss_t *boss_s, int i);
void display_systeme_qte(game_t *game);
void restart_clock_boss(game_t *game);
void display_key_rand(game_t *game);
void display_pop_art(game_t *game);
void systeme_fight(game_t *game);
void build_heart_boss(boss_t *boss_s, int i);
void display_heart_player(game_t *game);
void display_heart_boss(game_t *game);
void frame_three(game_t *game);
void build_button_next_boss(boss_t *boss_s, int i);
void build_msg_boss_zero(boss_t *boss_s, int i);
void build_msg_boss_one(boss_t *boss_s, int i);
void build_msg_boss_two(boss_t *boss_s, int i);
void build_os(boss_t *boss_s, int i);
void build_skelleton(boss_t *boss_s, int i);
void restart_clock_boss_animation(game_t *game);
void frame_four(game_t *game);
void frame_five(game_t *game);

#endif/* !BOSS_H */
