/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_tree
*/

#include "gameplay.h"

void display_tree(game_t *game, sprite_t *sprite, int x, int y)
{
    sfVector2f pos = {(x - game->map->pos_x) * 48 + 24,
    (y - game->map->pos_y) * 48};
    pos.x -= sprite->rect.width * sprite->scale.x - 16;
    pos.y -= sprite->rect.height * sprite->scale.y - 16;
    sfSprite_setPosition(sprite->sprite, pos);
    sfRenderWindow_drawSprite(game->game_info->window, sprite->sprite, NULL);
}
