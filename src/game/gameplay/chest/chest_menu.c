/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** chest_menu
*/

#include "gameplay.h"

chest_t *get_right_chest(game_t *game, int x, int y);

static const sfVector2f tab_scale[14] = {{0.2, 0.2}, {0.1, 0.1}, {0.5, 0.5},
{0.4, 0.4}, {0.5, 0.5}, {0.2, 0.2}, {0.4, 0.4}, {0.5, 0.5}, {0.5, 0.5},
{0.8, 0.8}, {0.2, 0.2}, {0.3, 0.3}, {0.1, 0.1}, {4, 4}};

sfVector2f get_scale_item(enum_item_t item)
{
    return (tab_scale[item]);
}

void display_item_in_chest(game_t *game)
{
    chest_t *chest = NULL;
    sfSprite *sprite = NULL;
    sfVector2f pos ={1445 + 109, 200};
    sfVector2f scale = {0, 0};

    if (game->chests->pos_chest == -1) {
        return;
    }
    chest = game->chests->chest[game->chests->pos_chest];
    if (chest->item->enum_item_e == NONE)
        return;
    scale = get_scale_item(chest->item->enum_item_e);
    sprite = chest->item->sprite_s[chest->item->enum_item_e]->sprite;
    sfSprite_setScale(sprite, scale);
    sfSprite_setPosition(sprite, pos);
    display_sprite(game, sprite);
}

void display_chest_menu(game_t *game)
{
    sfRenderWindow *win = game->game_info->window;
    tab_chest_t *temp = game->chests;
    temp->sprite_s->pos.x = 1445;

    if (temp->is_display == 1 && temp->sprite_s->pos.y < 0) {
        temp->sprite_s->pos.y += 20;
        sfSprite_setScale(temp->sprite_s->sprite, temp->sprite_s->scale);
        sfSprite_setPosition(temp->sprite_s->sprite, temp->sprite_s->pos);
    } else if (temp->is_display == -1 && temp->sprite_s->pos.y > -500) {
        temp->sprite_s->pos.y -= 30;
        sfSprite_setScale(temp->sprite_s->sprite, temp->sprite_s->scale);
        sfSprite_setPosition(temp->sprite_s->sprite, temp->sprite_s->pos);
    }
    sfRenderWindow_drawSprite(win, temp->sprite_s->sprite, NULL);
    if (temp->is_display == 1 && temp->sprite_s->pos.y >= 0) {
        display_item_in_chest(game);
    }
}

void try_open_chest(game_t *game)
{
    int x = game->map->x_player;
    int y = game->map->y_player;

    if (game->map->map_p[y -1][x] == 'C') {
        game->chests->is_display *= -1;
        game->chests->pos_chest = get_idx_chest(game, x, y - 1);
    }
}

void handle_chest(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[6]) {
        try_open_chest(game);
    }
}
