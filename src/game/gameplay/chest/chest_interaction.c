/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** chest_interaction
*/

#include "gameplay.h"

void try_update_quest(game_t *game, chest_t *chest)
{
    if (chest->item->enum_item_e == HAT &&
    game->quest->item_collected == 0
    && game->quest->current_level_quest == 0) {
        game->quest->item_collected = 1;
        game->quest->current_level_quest = 1;
        add_exp(game, 10);
        game->quest->mayor->idx_current_txt++;
    }
    if (chest->item->enum_item_e == BOOT &&
    game->quest->item_collected == 1
    && game->quest->current_level_quest == 1) {
        game->quest->item_collected = 2;
        game->quest->current_level_quest = 2;
        add_exp(game, 10);
        game->quest->mayor->idx_current_txt++;
    }
}

int get_idx_chest(game_t *game, int x, int y)
{
    for (int i = 0; i < 30; i++) {
        if (same_position(game->chests->chest[i], x, y) == 0) {
            return (i);
        }
    }
    return (-1);
}

void switch_item_chest_inv(game_t *game)
{
    item_t *item = get_specific_item(game, NONE);
    chest_t *chest = NULL;

    if (game->chests->pos_chest < 0 || item == NULL) {
        return;
    }
    chest = game->chests->chest[game->chests->pos_chest];
    try_update_quest(game, chest);
    item->enum_item_e = chest->item->enum_item_e;
    item->nb_item = chest->item->nb_item;
    chest->item->enum_item_e = NONE;
    chest->item->nb_item = 0;
}

void try_send_item(game_t *game, sfMouseButtonEvent mouse)
{
    sfIntRect pos = {1445, 0, 1920, 500};

    if (mouse.x > pos.left && mouse.x <= pos.width
    && mouse.y > pos.top && mouse.y <= pos.height) {
        switch_item_chest_inv(game);
    }
}

void handle_interaction_chest(game_t *game, sfMouseButtonEvent mouse)
{
    if (mouse.button != sfMouseLeft || game->chests->is_display == -1) {
        return;
    }
    try_send_item(game, mouse);
}
