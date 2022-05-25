/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** set_chest_map
*/

#include "gameplay.h"

static const enum_item_t item[7] = {AK47, CHOCO, BAT, BANDAGES,
SERRINGUE, CARROT, BREAD};

void do_to_chest(map_t *map, chest_t *chest[30])
{
    map->map_p[182][190] = 'C';
    chest[0]->sprite_s->pos = (sfVector2f){190, 182};
    chest[0]->item->enum_item_e = HAT;
    chest[0]->item->nb_item = 1;
    map->map_p[59][253] = 'C';
    chest[1]->sprite_s->pos = (sfVector2f){253, 59};
    chest[1]->item->enum_item_e = BOOT;
    chest[1]->item->nb_item = 1;
}

void set_map(map_t *map, chest_t *chest[30])
{
    int x = 0;
    int y = 0;

    do_to_chest(map, chest);
    for (int i = 2; i < 30;) {
        x = rand() % 600;
        y = rand() % 300;
        if (map->map_p[y][x] == ' ') {
            map->map_p[y][x] = 'C';
            chest[i]->sprite_s->pos.x = x;
            chest[i]->sprite_s->pos.y = y;
            chest[i]->item->enum_item_e = item[(rand() % 7)];
            chest[i]->item->nb_item = 1;
            i++;
        }
    }
}

int same_position(chest_t *chest, int x, int y)
{
    if (chest->sprite_s->pos.x == x && chest->sprite_s->pos.y == y) {
        return (0);
    }
    return (1);
}

chest_t *get_right_chest(game_t *game, int x, int y)
{
    for (int i = 0; i < 30; i++) {
        if (same_position(game->chests->chest[i], x, y) == 0) {
            return (game->chests->chest[i]);
        }
    }
    return (NULL);
}

void display_chest(game_t *game, int x, int y)
{
    chest_t *chest = get_right_chest(game, x, y);
    sfVector2f pos = {0, 0};
    pos.x = (x - game->map->pos_x) * 48;
    pos.y = (y - game->map->pos_y) * 48;

    if (chest == NULL) {
        return;
    } else if (chest->state == ALIVE) {
        pos.x -= chest->sprite_s->rect.width * chest->sprite_s->scale.x - 24;
        pos.y -= chest->sprite_s->rect.height * chest->sprite_s->scale.y - 24;
        sfSprite_setPosition(chest->sprite_s->sprite, pos);
        display_sprite(game, chest->sprite_s->sprite);
    }
}
