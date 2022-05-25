/*
** EPITECH PROJECT, 2022
** load_game.h
** File description:
** file.h with all protype for load_game part
*/

#ifndef LOAD_GAME_H_
    #define LOAD_GAME_H_

/******************************include*****************************************/

    #include "struct.h"

/******************************fonctions***************************************/

int active_default_value_load_game(game_t *game);
int init_load_game(game_t *game);
void start_load_game(game_t *game);
int analyse_event_load_game(game_t *game);
int save_game(game_t *game);
int create_save_empty_full(game_t *game);
int create_delete_save(game_t *game);
int create_support_save(game_t *game);
int my_arraylen(char **array);
int init_value_load_game(game_t *game);
int write_data_gameplay(int fd, game_t *game);
int write_data_player(int fd, game_t *game);
int write_int_save(int fd, int nb);
int write_str_save(int fd, char *str);
int check_save_file(game_t *game);
char *save_data_in_file(char *filepath, game_t *game);
char *read_file(char const *filepath);
int delete_data_file(game_t *game);
int display_save_one(game_t *game);
int display_save_two(game_t *game);
int display_save_three(game_t *game);
int check_hitbox_delete_save(game_t *game);
int check_hitbox_return_menu_button(game_t *game);
int check_hitbox_save_one(game_t *game);
int check_hitbox_save_two(game_t *game);
int check_hitbox_save_three(game_t *game);
int launch_save(game_t *game);
int restart_default_value_game(game_t *game);
void reset_map_as_a_virgin(game_t *game);
int create_save_charact(game_t *game, int i, char *filepath, int pos_x);
int create_name_charact(game_t *game, int i, int pos_x, int class);
void create_date_survivor(game_t *game, int i, int pos_x, char *time);

#endif/* !LOAD_GAME_H_ */
