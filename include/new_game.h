/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** new_game
*/

#ifndef NEW_GAME_H_
    #define NEW_GAME_H_

/******************************include*****************************************/

    #include "struct.h"

/******************************fonctions***************************************/

void start_new_game(game_t *game);
int init_new_game(game_t *game);
int analyse_event_new_game(game_t *game);
int active_default_value_new_game(game_t *game);
int create_class(game_t *game);
int create_cop_basic(game_t *game);
int create_cop_red(game_t *game);
int create_cop_blue(game_t *game);
int create_cop_green(game_t *game);
int create_cop_pink(game_t *game);
int create_researcher_basic(game_t *game);
int create_researcher_red(game_t *game);
int create_researcher_blue(game_t *game);
int create_researcher_green(game_t *game);
int create_researcher_pink(game_t *game);
int create_soldier_basic(game_t *game);
int create_soldier_red(game_t *game);
int create_soldier_blue(game_t *game);
int create_soldier_green(game_t *game);
int create_soldier_pink(game_t *game);
int create_sporty_basic(game_t *game);
int create_sporty_red(game_t *game);
int create_sporty_blue(game_t *game);
int create_sporty_green(game_t *game);
int create_sporty_pink(game_t *game);
int create_all_character(game_t *game);
int create_cat(game_t *game);
int move_animation_cat(game_t *game);
int check_hitbox_confirm_button(game_t *game);
int check_hitbox_tablet_button(game_t *game);
int check_hitbox_choose_class(game_t *game);
int check_hitbox_turn_character(game_t *game);
int restore_default_rotation_character(game_t *game);
int check_hitbox_reset_character(game_t *game);
int move_animation_reseau_charger(game_t *game);
int send_stat_character(game_t *game);
int clean_all_character(game_t *game);
int check_hitbox_first_color(game_t *game);
int init_stat_character(game_t *game);

#endif/* !NEW_GAME_H_ */
