/*
** EPITECH PROJECT, 2022
** check_hitbox_save_one.c
** File description:
** function that check hitbox of save one
*/

#include "rpg.h"

int check_hitbox_delete_button_one(game_t *game)
{
    if ((game->new_game->cursor.x > 690 && game->new_game->cursor.x < 738)
        && (game->new_game->cursor.y > 355 &&
        game->new_game->cursor.y < 400)) {
        game->load_game->delete = true;
        game->load_game->nb_save = 0;
        return (1);
    }
    return (0);
}

int check_hitbox_launch_save_one(game_t *game)
{
    if ((game->new_game->cursor.x > 385 && game->new_game->cursor.x < 754)
        && (game->new_game->cursor.y > 350 &&
        game->new_game->cursor.y < 914)) {
        game->load_game->nb_save = 0;
        launch_save(game);
    }
    return (0);
}

int check_hitbox_save_one(game_t *game)
{
    if (game->load_game->save[0] == true) {
        if (check_hitbox_delete_button_one(game) == 1)
            return (0);
        check_hitbox_launch_save_one(game);
    }
    return (0);
}
