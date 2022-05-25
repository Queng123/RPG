/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game
*/

#ifndef GAME_H_
    #define GAME_H_

/******************************include*****************************************/

    #include "struct.h"
    #include "pixel.h"
    #include "intro.h"
    #include "boss.h"
    #include "howtwoplay.h"

/******************************fonctions***************************************/

void display_game(game_t *game);
void display_inventory(game_t *game);
void display_pause(game_t *game);
void play_game(game_t *game);
void display_intro(game_t *game);
void build_game(game_t *game_s);
void analyse_event_gameplay(game_t *game);
int init_intro(game_t *game_s);
void handle_pause(game_t *game);
int init_pause(game_t *game);
void manage_pause_buttons(game_t *game, sfMouseButtonEvent event);
void display_button(button_t *button, sfRenderWindow *window);
void manage_date(game_t *game, sfMouseMoveEvent event);
void handle_tablet(game_t *game);
void display_tablet(game_t *game);
tablet_t *build_tablet(void);
void choose_tablet_screen(game_t *game);
sfVector2f set_pos(game_t *game, sfVector2f ratio);
void manage_skill_tree_buttons(game_t *game, sfVector2f click_pos);
void change_quest_tablet(game_t *game);
void display_cost_and_points(game_t *game);
void set_pos_skill_tree(game_t *game);
tablet_t *build_text_tablet(tablet_t *tablet);
void display_dialog(game_t *game);
void manage_handle_skill_tree(sfMouseMoveEvent event, game_t *game);
void change_statistic(game_t *game);
void display_player_info_text(game_t *game);
tablet_t *build_tablet_player_info(tablet_t *tablet);
void display_player_intellect(game_t *game);
void display_text_info(text_t *text, sfRenderWindow *window);

#endif/* !GAME_H_ */
