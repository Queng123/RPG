/*
** EPITECH PROJECT, 2022
** lol
** File description:
** sprite_player
*/

#include "player.h"

void change_sprite_direction(obj_t *obj, int y)
{
    if (obj->rect.top != y) {
        obj->rect.top = y;
        sfSprite_setTextureRect(obj->sprite, obj->rect);
    }
}

void update_sprite_obj(obj_t *temp)
{
    int x = temp->inertia.x;
    int y = temp->inertia.y;

    if (temp->type != ENEMY) {
        return;
    }
    if (temp->clock_sprite->seconds > 8 && (x != 0 || y != 0)) {
        temp->rect.left += 30;
        sfSprite_setTextureRect(temp->sprite, temp->rect);
        temp->clock_sprite->seconds = 0;
        sfClock_restart(temp->clock_sprite->clock);
    }
}

sfVector2f get_vector_to_mouse(game_t *game)
{
    sfVector2f res;
    sfVector2i pos = sfMouse_getPositionRenderWindow(game->game_info->window);

    res.x = (pos.x - ((game->map->x_player - game->map->pos_x) * 48));
    res.y = (pos.y - ((game->map->y_player - game->map->pos_y) * 48));
    return (res);
}

void get_orientation(game_t *game)
{
    sfVector2f vector_to_mouse = get_vector_to_mouse(game);
    int x = vector_to_mouse.x;
    int y = vector_to_mouse.y;

    if (game->gameplay->pause->display == true)
        return;
    if (x < 0 && y < 0) {
        change_sprite_direction(game->player->obj, 96);
    } else if (x > 0 && y > 0) {
        change_sprite_direction(game->player->obj, 0);
    }
    if (x > 0 && y < 0) {
        change_sprite_direction(game->player->obj, 64);
    } else if (x < 0 && y > 0) {
        change_sprite_direction(game->player->obj, 32);
    }
}

void get_orientation_zombie(game_t *game, obj_t *zombie)
{
    sfVector2f to_player = game->player->obj->pos;
    int x = (to_player.x - (zombie->pos.x - game->map->pos_x) * 48);
    int y = (to_player.y - (zombie->pos.y - game->map->pos_y) * 48);

    if (zombie->type != ENEMY)
        return;
    if (x < 0 && y < 0) {
        change_sprite_direction(zombie, 138);
        try_move_zombie(game, zombie, -1, Y);
    } else if (x > 0 && y > 0) {
        change_sprite_direction(zombie, 0);
        try_move_zombie(game, zombie, 1, Y);
    }
    if (x > 0 && y < 0) {
        change_sprite_direction(zombie, 92);
        try_move_zombie(game, zombie, 1, X);
    } else if (x < 0 && y > 0) {
        change_sprite_direction(zombie, 46);
        try_move_zombie(game, zombie, -1, X);
    }
    update_sprite_zombie(zombie);
}
