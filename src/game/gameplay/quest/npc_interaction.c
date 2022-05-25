/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** npc_interaction
*/

#include "gameplay.h"

npc_t *get_right_npc(game_t *game, int x, int y);

void is_first_interaction(game_t *game)
{
    if (game->quest->current_level_quest == -1
    && game->quest->item_collected == -1) {
        game->quest->current_level_quest = 0;
        game->quest->item_collected = 0;
    }
}

void try_interact_npc(game_t *game)
{
    int x = game->map->x_player;
    int y = game->map->y_player;
    npc_t *npc = NULL;
    if (game->map->map_p[y - 1][x] != 'N') {
        return;
    }
    npc = get_right_npc(game, x, y - 1);
    if (npc != NULL && npc != game->quest->seller) {
        is_first_interaction(game);
        game->quest->mayor->bull->rect.top = 348 * npc->idx_current_txt;
        game->quest->display_text = 2;
        game->quest->clock->seconds = 0;
        game->quest->mayor_talk = 1;
    } else if (npc == game->quest->seller) {
        game->quest->display_text = 1;
        game->quest->clock->seconds = 0;
        game->quest->is_display *= -1;
    }
}

void handle_interaction_npc(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[6]) {
        try_interact_npc(game);
    }
}
