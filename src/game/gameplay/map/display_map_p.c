/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_map_p
*/

#include "gameplay.h"

int handle_specific_case(game_t *game, char character, int y, int x)
{
    if (character == 'P') {
        display_player(game, 0);
        return (0);
    } else if (character == 'Z') {
        display_zombie(game, x, y);
        return (0);
    }
    if (character == 'C') {
        display_chest(game, x, y);
        return (0);
    } else if (character == 'N') {
        display_npc(game, x, y);
        return (0);
    }
    return (1);
}

sprite_t *get_right_sprite_p(game_t *game, char character, int y, int x)
{
    char *str = "mhHbsftcgwBoi@345TMv";
    map_t *map = game->map;

    if (handle_specific_case(game, character, y, x) == 0) {
        return (NULL);
    } else if (character == 't') {
        display_tree(game, map->ground_p[6], x, y);
        return (NULL);
    }
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == character) {
            return (map->ground_p[i]);
        }
    }
    return (NULL);
}

void check_if_display_line_adding_element(sprite_t *temp, sfVector2f pos,
sfRenderWindow *win)
{
    pos.x -= temp->rect.width * temp->scale.x - 16;
    pos.y -= temp->rect.height * temp->scale.y - 16;
    sfSprite_setPosition(temp->sprite, pos);
    sfRenderWindow_drawSprite(win, temp->sprite, NULL);
}

void display_line(game_t *game, int y, int pos_y)
{
    int i = 0;
    sprite_t *temp;
    sfVector2f pos = {0, 0};
    map_t *map = game->map;
    int pos_x = 0;
    sfRenderWindow *win = game->game_info->window;
    int plus = map->ratio * map->ground_g[0]->scale.x;
    pos.y = pos_y;

    for (int x = map->pos_x; i < 1980; i = i + 16, x++, pos_x += plus) {
        pos.x = pos_x;
        temp = get_right_sprite_p(game, map->map_p[y][x], y, x);
        if (temp != NULL) {
            check_if_display_line_adding_element(temp, pos, win);
        }
        pos.x = pos_x;
        pos.y = pos_y;
    }
}

void display_map_p(game_t *game)
{
    map_t *temp = game->map;
    int plus = temp->ratio * temp->ground_g[0]->scale.y;
    int i = 0;
    int pos = 0;

    for (int y = temp->pos_y; i < 1080; i = i + 16, y++, pos += plus) {
        display_line(game, y, pos);
    }
}
