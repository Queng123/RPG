/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** menu
*/

#ifndef MENU_H_
    #define MENU_H_

/******************************include*****************************************/

    #include "struct.h"

/******************************fonctions***************************************/

void display_menu(game_t *game);
void display_options(game_t *game);
void load_save(game_t *game);
void display_help(game_t *game);
void display_main_menu(game_t *game);
void display_history(game_t *game);
void display_howtoplay(game_t *game);
void display_tips(game_t *game);
void display_lobby(game_t *game);
int init_menu(game_t *game);
void analyse_event_menu(game_t *game);
int init_options(game_t *game);
void video_settings(game_t *game);
void audio_settings(game_t *game);
void choose_controls(game_t *game);
int init_audio(game_t *game);
int init_settings_bg(game_t *game);
void manage_audio_mouse_released(sfMouseButtonEvent event, game_t *game);
int init_colored_button(game_t *game);
sprite_t *build_bg(char *filepath);
void display_bg(sprite_t *bg, sfRenderWindow *win);
text_t *build_text(char *filepath);
void manage_video_mouse_released(sfMouseButtonEvent event, game_t *game);
int init_reseau(game_t *game);
int init_controls(game_t *game);
void analyse_control_wheel(sfMouseWheelEvent event, game_t *game);
void analyse_control_key(sfKeyEvent event, game_t *game);
void change_for_full_screen(game_t *game, sfVector2f click_pos);
void change_for_big_screen(game_t *game, sfVector2f click_pos);
void change_for_medium_screen(game_t *game, sfVector2f click_pos);
void change_for_small_screen(game_t *game, sfVector2f click_pos);
void manage_control_mouse_released(sfMouseButtonEvent event, game_t *game);
void manage_size_settings(game_t *game, sfVector2f click_pos);
int init_size(game_t *game);
int init_video(game_t *game);
void manage_options_mouse_released(sfMouseButtonEvent event, game_t *game);
void display_reseau(game_t *game);
void display_colored_button(game_t *game);
void create_button_particles(game_t *game);
void manage_menu_movement(sfMouseMoveEvent event, game_t *game);
void manage_menu_mouse_click(sfMouseButtonEvent event, game_t *game);

#endif/* !MENU_H_ */
