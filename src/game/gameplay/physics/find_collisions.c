/*
** EPITECH PROJECT, 2022
** PHYSIQUE_ENGINE
** File description:
** find_collisions
*/

#include "gameplay.h"
#include "physic.h"

void replace_obj(obj_t *obj1, obj_t *obj2)
{
    int temp = 0;

    if (get_hitbox_size(obj1, X) > obj2->pos.x) {
        temp = obj2->inertia.x;
        replace_obj_for_x_obj1(obj1, obj2, temp);
    } else if (obj1->pos.x < get_hitbox_size(obj2, X)) {
        temp = obj1->inertia.x;
        replace_obj_for_x_obj2(obj1, obj2, temp);
    }
    if (get_hitbox_size(obj1, Y) > obj2->pos.y) {
        temp = obj2->inertia.y;
        replace_obj_for_y_obj1(obj1, obj2, temp);
    } else if (obj1->pos.y < get_hitbox_size(obj2, Y)) {
        temp = obj1->inertia.y;
        replace_obj_for_y_obj2(obj1, obj2, temp);
    }
}

void find_type_collision(obj_t *obj1, obj_t *obj2)
{
    int temp = 0;
    temp += is_player_hit(obj1, obj2);
    temp += is_building_hit(obj1, obj2);

    if (temp == 0) {
        replace_obj(obj1, obj2);
    }
}

int is_hit(obj_t *first_obj, obj_t *obj)
{
    int x = first_obj->pos.x;
    int y = first_obj->pos.y;
    int xf = get_hitbox_size(first_obj, X);
    int yf = get_hitbox_size(first_obj, Y);
    int xsf = get_hitbox_size(obj, X);
    int ysf = get_hitbox_size(obj, Y);
    int xs = obj->pos.x;
    int ys = obj->pos.y;

    if (xf > xs && x < xsf && yf > ys && y < ysf) {
        find_type_collision(first_obj, obj);
        return (-1);
    }
    return (0);
}

void check_collision(game_t *game_s, obj_t *obj, int pos_obj)
{
    for (int i = 0; i < NB_ENT; i++) {
        if (game_s->entitie[i]->state_s == ALIVE && i != pos_obj) {
            is_hit(game_s->entitie[i], obj);
        }
    }
}
