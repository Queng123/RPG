/*
** EPITECH PROJECT, 2022
** analyse_event_new_game.c
** File description:
** function that analyse events of new_game
*/

#include "rpg.h"

int check_hitbox_new_game(game_t *game)
{
    check_hitbox_tablet_button(game);
    check_hitbox_choose_class(game);
    check_hitbox_confirm_button(game);
    check_hitbox_turn_character(game);
    check_hitbox_first_color(game);
    check_hitbox_reset_character(game);
    return (0);
}

int analyse_event_new_game(game_t *game)
{
    if (game->game_info->scene->actual_scene != NEW_GAME)
        return (0);
    if (game->event.type == sfEvtMouseMoved) {
        game->new_game->cursor.x = game->event.mouseMove.x;
        game->new_game->cursor.y = game->event.mouseMove.y;
    }
    if (game->event.type == sfEvtMouseButtonPressed)
        check_hitbox_new_game(game);
    return (0);
}
