/*
** EPITECH PROJECT, 2022
** lol
** File description:
** player
*/

#ifndef PLAYER_H_
    #define PLAYER_H_
    #include "struct.h"

    void display_sprite(game_t *game_s, sfSprite *sprite);

    int is_obj_click(game_t *game, obj_t *obj, sfMouseButtonEvent mouse);

    int get_hitbox_mid(obj_t *obj, axe_t idx);

    int get_hitbox_size(obj_t *obj, axe_t idx);

    int is_on_building(obj_t *first_obj, obj_t *obj);

    int calc_distance(obj_t *player, obj_t *zombie);

    int is_player_ready(game_t *game, int time);

    int get_sign(int x);

    void update_health_bar(obj_t *player, bar_t *health);

    int try_move_zombie(game_t *game, obj_t *zombie, int move, axe_t axe);

    int is_obj_click(game_t *game, obj_t *obj, sfMouseButtonEvent mouse);

    void player_shoot(game_t *game, sfMouseButtonEvent mouse);

    void reset_inventory_item(game_t *game);

    item_t *get_specific_item(game_t *game, enum_item_t item);

    int handle_buying(game_t *game, sfMouseButtonEvent mouse);

    int get_slot_clicked_by_mouse(sfMouseButtonEvent mouse, int start, int end);

    int try_add_item(game_t *game, enum_item_t item_to_add, int nb_item);

    int get_damage_mele_weapon(player_t *player);

    int get_speed_running(game_t *game);

    void update_stamina(game_t *game);

    void decrease_movement(game_t *game);

    void update_sprite_zombie(obj_t *obj);

#endif/* !PLAYER_H_ */
