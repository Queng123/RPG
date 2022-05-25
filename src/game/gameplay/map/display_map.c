/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_map
*/

#include "gameplay.h"

void init_generator(game_t *game)
{
    if (game->generator->display == true && game->game_info->particles_on == 1)
        use_generator(game->generator, 0.01, game->game_info->window);
    else
        game->generator->display = false;
    if (game->generator->heal == 1 && game->game_info->particles_on == 1)
        use_generator(game->generator, 0.01, game->game_info->window);
    else
        game->generator->heal = 0;
    display_near_dead_obj(game);
    display_map_p(game);
    if (game->gameplay->timer->seconds > 1 &&
    game->gameplay->pause->display == false) {
        game->gameplay->timer->seconds = 0;
        game->gameplay->time += 1;
    }
    print_time(game->gameplay->time, game->gameplay->date,
    game->game_info->window, game);
}

sprite_t *get_right_sprite(map_t *map, char character)
{
    char *str = "dxr BsbRA";

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == character) {
            return (map->ground_g[i]);
        }
    }
    return (NULL);
}

void display_full_line(map_t *map, sfRenderWindow *win, int y, int pos_y)
{
    int i = 0;
    sprite_t *temp;
    sfVector2f pos = {0, 0};
    int plus = map->ratio * map->ground_g[0]->scale.x;
    pos.y = pos_y;
    int pos_x = 0;

    for (int x = map->pos_x; i < 1980; i = i + 16, x++, pos_x += plus) {
        pos.x = pos_x;
        if (x > map->max_x) {
            return;
        }
        temp = get_right_sprite(map, map->map_g[y][x]);
        if (temp != NULL) {
            sfSprite_setScale(temp->sprite, temp->scale);
            sfSprite_setPosition(temp->sprite, pos);
            sfRenderWindow_drawSprite(win, temp->sprite, NULL);
        }
    }
}

void display_full_map(game_t *game)
{
    map_t *temp = game->map;
    int plus = temp->ratio * temp->ground_g[0]->scale.y;
    int i = 0;
    int pos = 0;

    for (int y = temp->pos_y; i < 1080; i = i + 16, y++, pos += plus) {
        if (y >= temp->max_y)
            return;
        display_full_line(temp, game->game_info->window, y, pos);
    }
    init_generator(game);
}
