/*
** EPITECH PROJECT, 2022
** lol
** File description:
** zombies
*/

#ifndef ZOMBIES_H_
    #define ZOMBIES_H_
    #include "struct.h"
    #include "math.h"
    #include <stdlib.h>

    int get_hitbox_mid(obj_t *obj, axe_t idx);

    int get_hitbox_size(obj_t *obj, axe_t idx);

    void display_sprite(game_t *game_s, sfSprite *sprite);

    int calc_distance(obj_t *player, obj_t *zombie);

    void update_health_bar(obj_t *player, bar_t *health);

    int is_zombie(obj_t *obj, state_t choosen_state);

    int try_move_zombie(game_t *game, obj_t *zombie, int move, axe_t axe);

    void get_orientation_zombie(game_t *game, obj_t *zombie);

    void try_add_item(game_t *game, enum_item_t item_to_add, int nb_item);

    void generate_random_pos(map_t *map, obj_t *obj);

    void handle_player_death(game_t *game);

    void add_exp(game_t *game, int add);

    void update_sprite_zombie(obj_t *obj);

#endif/* !ZOMBIES_H_ */
