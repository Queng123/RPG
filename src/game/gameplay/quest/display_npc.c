/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_npc
*/

#include "gameplay.h"

void set_npc_map(map_t *map, quest_t *quest)
{
    int x = 476;
    int y = 210;

    quest->seller->npc->pos = (sfVector2f){x, y};
    map->map_p[y][x] = 'N';
    x = 446;
    quest->mayor->npc->pos = (sfVector2f){x, y};
    map->map_p[y][x] = 'N';
}

static int is_same_position(npc_t *npc, int x, int y)
{
    if (npc->npc->pos.x == x && npc->npc->pos.y == y) {
        return (0);
    }
    return (1);
}

npc_t *get_right_npc(game_t *game, int x, int y)
{
    if (is_same_position(game->quest->mayor, x, y) == 0) {
        return (game->quest->mayor);
    } else if (is_same_position(game->quest->seller, x, y) == 0) {
        return (game->quest->seller);
    }
    return (NULL);
}

void display_npc(game_t *game, int x, int y)
{
    npc_t *npc = get_right_npc(game, x, y);
    sfVector2f pos = {0, 0};
    pos.x = (x - game->map->pos_x) * 48;
    pos.y = (y - game->map->pos_y) * 48;

    if (npc == NULL) {
        return;
    }
    pos.x -= npc->npc->rect.width * npc->npc->scale.x - 24;
    pos.y -= npc->npc->rect.height * npc->npc->scale.y - 24;
    sfSprite_setPosition(npc->npc->sprite, pos);
    sfSprite_setScale(npc->npc->sprite, npc->npc->scale);
    display_sprite(game, npc->npc->sprite);
}
