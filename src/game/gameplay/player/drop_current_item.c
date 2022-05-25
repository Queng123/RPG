/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** drop_current_item
*/

#include "player.h"

void handle_drop_item(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[7]) {
        game->player->item_hand->enum_item_e = HAND;
        game->player->item_hand->nb_item = 0;
    }
}
