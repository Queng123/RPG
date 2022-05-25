/*
** EPITECH PROJECT, 2022
** analyse_event_load_game.c
** File description:
** function that analyse event of load_game part
*/

#include "rpg.h"

int check_hitbox_load_game(game_t *game)
{
    if (game->load_game->delete == false) {
        check_hitbox_return_menu_button(game);
        check_hitbox_save_one(game);
        check_hitbox_save_two(game);
        check_hitbox_save_three(game);
    } else {
        check_hitbox_delete_save(game);
    }
    return (0);
}

int analyse_event_load_game(game_t *game)
{
    if (game->game_info->scene->actual_scene != LOAD_GAME)
        return (0);
    if (game->event.type == sfEvtMouseMoved) {
        game->new_game->cursor.x = game->event.mouseMove.x;
        game->new_game->cursor.y = game->event.mouseMove.y;
    }
    if (game->event.type == sfEvtMouseButtonPressed)
        check_hitbox_load_game(game);
    return (0);
}
