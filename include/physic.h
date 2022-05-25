/*
** EPITECH PROJECT, 2022
** lol
** File description:
** physic
*/

#ifndef PHYSIC_H_
    #define PHYSIC_H_
    #include "struct.h"

    void replace_obj(obj_t *obj1, obj_t *obj2);

    void find_type_collision(obj_t *obj1, obj_t *obj2);

    int is_hit(obj_t *first_obj, obj_t *obj);

    void check_collision(game_t *game_s, obj_t *obj, int pos_obj);

    void change_state(game_t *game_s);

    void handle_friction(obj_t *obj, float time);

    int get_hitbox_size(obj_t *obj, axe_t idx);

    int get_hitbox_mid(obj_t *obj, axe_t idx);

    void replace_obj_for_x_obj1(obj_t *obj1, obj_t *obj2, int temp);

    void replace_obj_for_x_obj2(obj_t *obj1, obj_t *obj2, int temp);

    void replace_obj_for_y_obj1(obj_t *obj1, obj_t *obj2, int temp);

    void replace_obj_for_y_obj2(obj_t *obj1, obj_t *obj2, int temp);

    int is_player_hit(obj_t *obj1, obj_t *obj2);

    int is_building_hit(obj_t *obj1, obj_t *obj2);

    void update_zombie_pos(obj_t *zombie);

#endif /* !PHYSIC_H_ */
