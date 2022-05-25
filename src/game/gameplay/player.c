/*
** EPITECH PROJECT, 2022
** physique_engine
** File description:
** player
*/

#include "gameplay.h"

void despawn_zombie(map_t *map, obj_t *obj)
{
    int x = obj->pos.x;
    int y = obj->pos.y;

    if (obj->state_s != ALIVE && obj->type != ENEMY) {
        return;
    }
    obj->state_s = DEAD;
    map->map_p[y][x] = ' ';
}

void handle_physique_window(map_t *map, obj_t *obj)
{
    int x_max = map->pos_x + 120 + 30;
    int y_max = map->pos_y + 67 + 30;

    if (obj->pos.x < map->pos_x - 30) {
        despawn_zombie(map, obj);
        return;
    } else if (obj->pos.x > x_max) {
        despawn_zombie(map, obj);
        return;
    }
    if (obj->pos.y < map->pos_y - 30) {
        despawn_zombie(map, obj);
        return;
    } else if (obj->pos.y > y_max) {
        despawn_zombie(map, obj);
        return;
    }
}

void move_obj(obj_t *obj)
{
    sfSprite_setScale(obj->sprite, obj->scale);
    sfSprite_setPosition(obj->sprite, obj->pos);
}

void display_player(game_t *game_s, float move)
{
    get_orientation(game_s);
    update_sprite_obj(game_s->player->obj);
    move_obj(game_s->player->obj);
    handle_friction(game_s->player->obj, move);
    display_sprite(game_s, game_s->player->obj->sprite);
}

void display_obj(game_t *game_s)
{
    play_song(game_s);
    display_full_map(game_s);
    attack_player(game_s);
    for (int i = 0; i < NB_ENT; i++) {
        if (game_s->entitie[i]->state_s == ALIVE) {
            move_obj(game_s->entitie[i]);
            move_to_player(game_s, game_s->entitie[i]);
            update_sprite_obj(game_s->entitie[i]);
            handle_physique_window(game_s->map, game_s->entitie[i]);
        }
    }
    display_sell_book(game_s);
    display_player_health_stamina(game_s);
    display_chest_menu(game_s);
}
