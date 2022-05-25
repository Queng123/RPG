/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_map
*/

#include "build.h"

void build_player_pos(map_t *map)
{
    int x = map->pos_x;
    int y = map->pos_y;

    for (int i = 0; i < 1980 / 6; i += 16, x++) {}
    for (int i = 0; i < 1080 / 6; i += 16, y++) {}
    y++;
    x++;
    map->map_p[y][x] = 'P';
    map->x_player = x;
    map->y_player = y;
}

char **get_file_map(char *filepath)
{
    FILE *fichier = fopen(filepath, "r");
    size_t size = 661;
    char *res = malloc(sizeof(char) * (size + 3));
    char **tab = malloc(sizeof(char *) * (320 + 3));
    int i = 0;

    if (fichier == NULL || res == NULL || tab == NULL)
        return (NULL);
    for (; i < 320 && getline(&res, &size, fichier) != -1; i++) {
        tab[i] = res;
        res = malloc(sizeof(char) * (size + 3));
        if (res == NULL) {
            return (NULL);
        }
    }
    tab[i] = NULL;
    return (tab);
}

int build_tab_sprite(sprite_t *tab[8])
{
    sfIntRect rect = {0, 0, 16, 16};
    sfIntRect rect_g = {0, 0, 80, 80};
    sfVector2f pos = {0, 0};
    sfVector2f scale = {3, 3};
    sfVector2f scale_g = {0.58, 0.58};
    sfVector2f scale_a = {0.125, 0.125};

    tab[0] = build_sprit(rect, "assets/game/dirt.jpg", scale, pos);
    tab[1] = build_sprit(rect, "assets/game/grass.jpg", scale, pos);
    tab[2] = build_sprit(rect, "assets/game/road.jpg", scale, pos);
    tab[3] = build_sprit(rect, "assets/game/water.jpg", scale, pos);
    tab[4] = build_sprit(rect, "assets/game/pave.jpg", scale, pos);
    tab[5] = build_sprit(rect, "assets/game/sand.jpg", scale, pos);
    tab[6] = build_sprit(rect, "assets/game/wallfoot.jpg", scale, pos);
    tab[7] = build_sprit(rect_g, "assets/game/ground_mineshaft.jpg",
    scale_g, pos);
    tab[8] = build_sprit((sfIntRect){0, 0, 400, 400},
    "assets/game/albedo_ground.jpg", scale_a, pos);
    return (0);
}

int build_tab_sprite_p(sprite_t *tab[20])
{
    sfVector2f pos = {0, 0};
    sfVector2f scale = {3, 3};

    build_tab_sprite_p_tab_zero_nine(tab, pos, scale);
    build_tab_sprite_p_tab_nine_fivety(tab, pos, scale);
    tab[15] = build_sprit((sfIntRect){0, 0, 146, 145},
    "assets/game/house4.png", scale, pos);
    tab[16] = build_sprit((sfIntRect){1, 0, 144, 143},
    "assets/game/house5.png", (sfVector2f){3.5, 3.5}, pos);
    tab[17] = build_sprit((sfIntRect){0, 0, 181, 183},
    "assets/game/townhall.png", (sfVector2f){3.5, 3.5}, pos);
    tab[18] = build_sprit((sfIntRect){0, 0, 411, 257},
    "assets/game/minenetrance.png", (sfVector2f){1, 1}, pos);
    tab[19] = build_sprit((sfIntRect){0, 0, 31, 35},
    "assets/game/bushe.png", (sfVector2f){2, 2}, pos);
    return (0);
}

map_t *build_map(char *filepath)
{
    map_t *map = malloc(sizeof(map_t));
    char **map_temp = get_file_map(filepath);
    char **temp_map = get_file_map("data/map_p.uwu");

    if (map == NULL || map_temp == NULL || temp_map == NULL) {
        return (NULL);
    }
    map->map_g = map_temp;
    map->map_p = temp_map;
    map->max_x = 661;
    map->max_y = 320;
    map->pos_x = 461;
    map->pos_y = 164;
    map->ratio = 16;
    build_tab_sprite(map->ground_g);
    build_tab_sprite_p(map->ground_p);
    build_player_pos(map);
    return (map);
}
