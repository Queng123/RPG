/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** analyse_event
*/

#include "rpg.h"

void analyse_event(sfEvent event, game_t *game)
{
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(game->game_info->window);
    }
    analyse_event_gameplay(game);
    analyse_event_menu(game);
    analyse_event_new_game(game);
    analyse_event_boss(game);
    analyse_event_load_game(game);
}
