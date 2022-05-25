/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_attack
*/

#include "player.h"
#include <stdio.h>
#include <math.h>

int is_enemie_in_range(game_t *game, obj_t *enemy)
{
    obj_t *player = game->player->obj;
    int range = 100;
    int px = player->pos.x + player->rect.width * player->scale.x / 2;
    int py = player->pos.y + player->rect.height * player->scale.y / 2;
    int distance_x = (enemy->pos.x - game->map->pos_x) * 48 - px;
    int distance_y = (enemy->pos.y - game->map->pos_y) * 48 - py;
    int distance = sqrt((distance_x * distance_x + distance_y * distance_y));

    if (distance < range) {
        return (1);
    }
    return (-1);
}

int is_player_ready(game_t *game, int time)
{
    obj_t *player = game->player->obj;

    if (player->clock_attack->seconds > time) {
        player->clock_attack->seconds = 0;
        sfClock_restart(player->clock_attack->clock);
        return (1);
    }
    return (-1);
}

int try_attack(game_t *game, obj_t *obj, sfMouseButtonEvent mouse)
{
    int damage = get_damage_mele_weapon(game->player);

    if (is_enemie_in_range(game, obj) != 1) {
        return (-1);
    } else
    if (is_obj_click(game, obj, mouse) == 0) {
        obj->hp -= game->player->stat->strength + damage;
        game->player->stamina -= 10;
        return (1);
    }
    return (0);
}

void player_punch(game_t *game, sfMouseButtonEvent mouse)
{
    obj_t *temp;
    player_t *player = game->player;
    sfVector2f click_pos = (sfVector2f){mouse.y + 30, mouse.x};
    sfColor red = {115, 8, 0, 255};

    if ((player->item_hand->enum_item_e != BAT &&
    player->item_hand->enum_item_e != HAND) ||
    is_player_ready(game, 10) != 1 || player->stamina < 10)
        return;
    for (int i = 0; i < NB_ENT; i++) {
        temp = game->entitie[i];
        if (temp->state_s == ALIVE && try_attack(game, temp, mouse) == 1) {
            if (game->generator->display == false) {
                click_pos = (sfVector2f){(temp->pos.y - game->map->pos_y) * 48,
                (temp->pos.x - game->map->pos_x) * 48};
                game->generator =
                fill_generator(game->generator, click_pos, red, sfBlack);
            }
            return;
        }
    }
}

void player_attack(game_t *game, sfMouseButtonEvent mouse)
{
    if (game->player->inventory->backpack->pos.y <= 500) {
        return;
    }
    player_punch(game, mouse);
    player_shoot(game, mouse);
}
