/*
** EPITECH PROJECT, 2022
** check_hitbox_save_three.c
** File description:
** function that check the hitbox of save three
*/

#include "rpg.h"

int check_hitbox_delete_button_three(game_t *game)
{
    if ((game->new_game->cursor.x > 1470 && game->new_game->cursor.x < 1520)
        && (game->new_game->cursor.y > 355 &&
        game->new_game->cursor.y < 400)) {
        game->load_game->delete = true;
        game->load_game->nb_save = 2;
        return (1);
    }
    return (0);
}

int check_hitbox_launch_save_three(game_t *game)
{
    if ((game->new_game->cursor.x > 1165 && game->new_game->cursor.x < 1534)
        && (game->new_game->cursor.y > 350 &&
        game->new_game->cursor.y < 914)) {
        game->load_game->nb_save = 2;
        launch_save(game);
    }
    return (0);
}

int check_hitbox_save_three(game_t *game)
{
    if (game->load_game->save[2] == true) {
        if (check_hitbox_delete_button_three(game) == 1)
            return (0);
        check_hitbox_launch_save_three(game);
    }
    return (0);
}
