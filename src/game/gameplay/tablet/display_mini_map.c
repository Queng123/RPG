/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_mini_map
*/

#include "rpg.h"

static sfSprite *get_right_sprite(map_t *map, char character)
{
    char *str = "dxr Bsb";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == character) {
            return (map->ground_g[i]->sprite);
        }
    }
    return (NULL);
}

void display_mini_line(map_t *map, sfRenderWindow *win, int y, int pos_y)
{
    int i = 0;
    sfSprite *temp;
    sfVector2f pos = {0, 0};
    sfVector2f scale = {1.5, 1.5};
    int plus = 8;
    pos.y = pos_y;
    int pos_x = 113;

    for (int x = map->pos_x; i < 740; i = i + 8, x++, pos_x += plus) {
        pos.x = pos_x;
        if (x > map->max_x) {
            return;
        }
        temp = get_right_sprite(map, map->map_g[y][x]);
        if (temp != NULL) {
            sfSprite_setScale(temp, scale);
            sfSprite_setPosition(temp, pos);
            sfRenderWindow_drawSprite(win, temp, NULL);
        }
    }
}

void display_mini_map(game_t *game)
{
    map_t *temp = game->map;
    int plus = 8;
    int i = 0;
    int pos = 460;

    for (int y = temp->pos_y; i < 505; i = i + 8, y++, pos += plus) {
        if (y >= temp->max_y) {
            return;
        }
        display_mini_line(temp, game->game_info->window, y, pos);
    }
}
