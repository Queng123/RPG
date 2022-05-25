/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** analyse_event_functions
*/

#include "event.h"

void handle_key_pressed(game_t *game)
{
    handle_movement(game);
    handle_inventory(game);
    handle_tablet(game);
    handle_sleeping(game);
    handle_chest(game);
    handle_interaction_npc(game);
    handle_drop_item(game);
    handle_run(game);
    handle_mine_entrance(game);
}

void handle_click(game_t *game)
{
    player_attack(game, game->event.mouseButton);
    click_inventory(game, game->event.mouseButton);
    try_heal_player(game, game->event.mouseButton);
    handle_interaction_chest(game, game->event.mouseButton);
    hanle_seller_interaction(game, game->event.mouseButton);
    click_tablet(game, game->event.mouseButton);
}
