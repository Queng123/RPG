/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** event
*/

#ifndef EVENT_H_
    #define EVENT_H_
    #include "struct.h"

void move_entitie(game_t *game, int move, axe_t axe);

void update_sprite_player_move(obj_t *temp);

void update_inventory(game_t *game, int new_state);

void handle_sleeping(game_t *game);

void handle_chest(game_t *game);

void handle_interaction_chest(game_t *game, sfMouseButtonEvent mouse);

void handle_interaction_npc(game_t *game);

int handle_buying(game_t *game, sfMouseButtonEvent mouse);

void hanle_seller_interaction(game_t *game, sfMouseButtonEvent mouse);

void handle_pause(game_t *game);

void handle_tablet(game_t *game);

void click_inventory(game_t *game, sfMouseButtonEvent mouse);

void player_attack(game_t *game, sfMouseButtonEvent mouse);

void try_heal_player(game_t *game, sfMouseButtonEvent mouse);

void click_tablet(game_t *game, sfMouseButtonEvent event);

void manage_pause_buttons(game_t *game, sfMouseButtonEvent event);

void handle_key_pressed(game_t *game);

void handle_click(game_t *game);

void handle_inventory(game_t *game);

void handle_movement(game_t *game);

void handle_drop_item(game_t *game);

int get_speed_running(game_t *game);

void handle_run(game_t *game);

void handle_mine_entrance(game_t *game);

void decrease_movement(game_t *game);

#endif/* !EVENT_H_ */
