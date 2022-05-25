/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** player_shooting
*/

#include "player.h"

void get_shot(game_t *game, obj_t *target, sfVector2f click_pos)
{
    sfColor red = {115, 8, 0, 255};

    if (game->generator->display == false) {
        click_pos = (sfVector2f){(target->pos.y - game->map->pos_y) * 48,
        (target->pos.x - game->map->pos_x) * 48};
        game->generator = fill_generator(game->generator,
        click_pos, red, sfBlack);
    }
}

item_t *get_specific_item(game_t *game, enum_item_t item)
{
    inventory_t *inv = game->player->inventory;

    for (int i = 0; i < 12; i++) {
        if (inv->items[i]->enum_item_e == item) {
            return (inv->items[i]);
        }
    }
    return (NULL);
}

int get_nb_item(game_t *game, enum_item_t item)
{
    inventory_t *inv = game->player->inventory;

    for (int i = 0; i < 12; i++) {
        if (inv->items[i]->enum_item_e == item) {
            return (inv->items[i]->nb_item);
        }
    }
    return (-1);
}

obj_t *get_zombie_aimed(game_t *game, sfMouseButtonEvent mouse)
{
    obj_t *obj = NULL;

    for (int i = 0; i < NB_ENT; i++) {
        obj = game->entitie[i];
        if (obj->state_s == ALIVE && is_obj_click(game, obj, mouse) == 0) {
            return (obj);
        }
    }
    return (NULL);
}

void player_shoot(game_t *game, sfMouseButtonEvent mouse)
{
    player_t *player = game->player;
    sfSound *temp = game->audio->ak_sound;
    obj_t *target = NULL;
    item_t *ammunation = get_specific_item(game, AMMO);
    sfVector2f click_pos = {mouse.y, mouse.x};
    int ammo = get_nb_item(game, AMMO);
    int random = 5 * game->player->stat->shoot;

    if (player->item_hand->enum_item_e != AK47 || ammo <= 0
    || ammunation == NULL)
        return;
    target = get_zombie_aimed(game, mouse);
    if (target != NULL && ammo >= 1 && ammunation != NULL) {
        get_shot(game, target, click_pos);
        if ((rand() % random) != 1)
            target->hp -= 30;
    }
    ammunation->nb_item -= 1;
    sfSound_play(temp);
}
