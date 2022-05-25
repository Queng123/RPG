/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** zombies_attack
*/

#include "zombies.h"

int is_zombie(obj_t *obj, state_t choosen_state)
{
    if (obj->type == ENEMY && obj->state_s == choosen_state) {
        return (0);
    }
    return (1);
}

int is_zombie_ready(obj_t *obj)
{
    if (obj->clock_attack->seconds > 20) {
        return (0);
    }
    return (-1);
}

int is_player_in_range(obj_t *zombie, game_t *game)
{
    int range = 100;
    obj_t *player = game->player->obj;
    int px = player->pos.x + player->rect.width * player->scale.x / 2;
    int py = player->pos.y + player->rect.height * player->scale.y / 2;
    int distance_x = (zombie->pos.x - game->map->pos_x) * 48 - px;
    int distance_y = (zombie->pos.y - game->map->pos_y) * 48 - py;
    int distance = sqrt((distance_x * distance_x + distance_y * distance_y));

    if (distance < range) {
        return (1);
    }
    return (-1);
}

void try_attack_zombie(game_t *game, obj_t *obj)
{
    obj_t *player = game->player->obj;

    if (is_zombie_ready(obj) == 0 && is_player_in_range(obj, game) == 1) {
        player->hp -= obj->damage;
        update_health_bar(game->player->obj, game->player->health);
        obj->clock_attack->seconds = 0;
        sfClock_restart(obj->clock_attack->clock);
        handle_player_death(game);
    }
}

void attack_player(game_t *game)
{
    for (int i = 0; i < NB_ENT; i++) {
        if (is_zombie(game->entitie[i], ALIVE) == 0) {
            try_attack_zombie(game, game->entitie[i]);
        }
    }
}
