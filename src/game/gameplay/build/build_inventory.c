/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** build_inventory
*/

#include "build.h"

static const sfIntRect tab_rect[14] = {{0, 0, 323, 323}, {0, 0, 520, 152},
{0, 0, 116, 100}, {0, 0, 143, 83}, {0, 0, 162, 89}, {0, 0, 161, 262},
{0, 0, 130, 131}, {0, 0, 145, 94}, {0, 0, 96, 93}, {0, 0, 85, 52},
{0, 0, 172, 321}, {0, 0, 202, 168}, {0, 0, 518, 564}, {0, 0, 23, 12}};

static const sfVector2f tab_scale[14] = {{0.2, 0.2}, {0.1, 0.1}, {0.5, 0.5},
{0.4, 0.4}, {0.5, 0.5}, {0.2, 0.2}, {0.4, 0.4}, {0.5, 0.5}, {0.5, 0.5},
{0.8, 0.8}, {0.2, 0.2}, {0.3, 0.3}, {0.1, 0.1}, {2, 2}};

static const char *filepath[14] = {"assets/assets/batleft.png",
"assets/assets/ak47lrft.png", "assets/assets/medkit.png",
"assets/assets/bread.png", "assets/game/chocolatine.png",
"assets/assets/carrot.png", "assets/assets/key.png",
"assets/assets/letter.png", "assets/assets/money.png",
"assets/assets/ammo.png", "assets/assets/seringue.png", "assets/game/hand.png",
"assets/game/bootsis.png", "assets/game/sisterhat.png"};

sprite_t **build_tab_sprite_items(void)
{
    sprite_t **tab = malloc(sizeof(sprite_t *) * 14);
    sprite_t *temp = NULL;
    sfVector2f pos = {0, 0};

    if (tab == NULL) {
        return (NULL);
    }
    for (int i = 0; i < 14; i++) {
        temp = build_sprit(tab_rect[i], filepath[i], tab_scale[i], pos);
        if (temp == NULL) {
            return (NULL);
        }
        tab[i] = temp;
    }
    tab[14] = NULL;
    return (tab);
}

int build_items(item_t *item[16])
{
    sprite_t **tab = build_tab_sprite_items();
    item_t *item_temp = malloc(sizeof(item_t));

    if (tab == NULL || item == NULL) {
        return (84);
    }
    for (int i = 0; i < 12; i++) {
        item_temp->enum_item_e = NONE;
        item_temp->nb_item = 1;
        item_temp->sprite_s = tab;
        item[i] = item_temp;
        item_temp = malloc(sizeof(item_t));
        if (item_temp == NULL)
            return (84);
    }
    item[10]->enum_item_e = MONEY;
    item[10]->nb_item = 1000;
    return (0);
}

void build_inventory_event(inventory_t *inventory, sprite_t *bag,
sprite_t *bloc, sprite_t *switch_b)
{
    inventory->backpack = bag;
    inventory->is_display = -1;
    inventory->square = bloc;
    inventory->switch_b = switch_b;
    inventory->is_clicked = -1;
    inventory->item_idx = -1;
}

inventory_t *build_inventory(void)
{
    sfIntRect rect = {0, 0, 832, 674};
    sfIntRect rectb = {0, 0, 79, 79};
    sfIntRect rb = {0, 0, 127, 141};
    sfVector2f scale = {1, 1};
    sfVector2f scb = {0.5, 0.5};
    sfVector2f pos = {1148, 1080};
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sprite_t *bag = build_sprit(rect, "assets/game/bag.png", scale, pos);
    sprite_t *bloc = build_sprit(rectb, "assets/game/bloc.png", scale, pos);
    sprite_t *switch_b =
    build_sprit(rb, "assets/game/switch_replace.png", scb, pos);
    inventory->text = build_text("assets/font/verdana.ttf");

    if (inventory == NULL || bag == NULL || bloc == NULL || switch_b == NULL
    || inventory->text == NULL)
        return (NULL);
    build_inventory_event(inventory, bag, bloc, switch_b);
    if (build_items(inventory->items) == 84)
        return (NULL);
    return (inventory);
}
