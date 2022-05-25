/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_chest
*/

#include "build.h"

void reset_map_as_a_virgin(game_t *game)
{
    char **map = NULL;
    int x = 0;
    int y = 0;

    if (game->map == NULL || game->chests == NULL)
        return;
    map = game->map->map_p;
    for (int i = 0; i < 30; i++) {
        x = game->chests->chest[i]->sprite_s->pos.x;
        y = game->chests->chest[i]->sprite_s->pos.y;
        map[y][x] = ' ';
    }
}

item_t *build_items_chest(int nb_item, enum_item_t item_type, sprite_t **sprite)
{
    item_t *item = malloc(sizeof(item_t));

    if (item == NULL)
        return (NULL);
    item->nb_item = nb_item;
    item->enum_item_e = item_type;
    item->sprite_s = sprite;
    return (item);
}

chest_t *build_chest(sprite_t **sprite, char *filepath)
{
    chest_t *chest = malloc(sizeof(chest_t));
    sfIntRect rect = {0, 0, 43, 35};
    sfVector2f scale = {1.5, 2};
    sfVector2f pos = {0, 0};

    if (chest == NULL) {
        return (NULL);
    }
    chest->item = build_items_chest(1, HAT, sprite);
    chest->sprite_s = build_sprit(rect, filepath, scale, pos);
    chest->state = ALIVE;
    if (chest->item == NULL || chest->sprite_s == NULL) {
        return (NULL);
    }
    return (chest);
}

int load_tab_chest(char *filepath, sprite_t **sprite, chest_t *chest[30])
{
    int pos_start = 436;

    for (int i = 0; i < 30; i++) {
        chest[i] = build_chest(sprite, filepath);
        if (chest[i] == NULL) {
            return (84);
        }
        if (i <= 15) {
            chest[i]->item->enum_item_e = BOOT;
        }
        chest[i]->sprite_s->pos = (sfVector2f) {pos_start + i, 197};
    }
    return (0);
}

tab_chest_t *build_tab_chest(char *filepath, sprite_t **sprite)
{
    tab_chest_t *tab = malloc(sizeof(tab_chest_t));
    sfIntRect rect = {0, 0, 445, 500};
    sfVector2f sca = {1, 1};
    sfVector2f pos = {0, 0};

    if (tab == NULL)
        return (NULL);

    if (load_tab_chest(filepath, sprite, tab->chest) == 84) {
        return (NULL);
    }
    tab->sprite_s = build_sprit(rect, "assets/game/chest_menu.png", sca, pos);
    if (tab->sprite_s == NULL) {
        return (NULL);
    }
    tab->is_display = -1;
    return (tab);
}
