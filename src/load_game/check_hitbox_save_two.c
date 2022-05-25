/*
** EPITECH PROJECT, 2022
** check_hitbox_save_two.c
** File description:
** function that check the hitbox of save two
*/

#include "rpg.h"

int check_hitbox_delete_button_two(game_t *game)
{
    if ((game->new_game->cursor.x > 1080 && game->new_game->cursor.x < 1130)
        && (game->new_game->cursor.y > 355 &&
        game->new_game->cursor.y < 400)) {
        game->load_game->delete = true;
        game->load_game->nb_save = 1;
        return (1);
    }
    return (0);
}

int check_hitbox_launch_save_two(game_t *game)
{
    if ((game->new_game->cursor.x > 775 && game->new_game->cursor.x < 1144)
        && (game->new_game->cursor.y > 350 &&
        game->new_game->cursor.y < 914)) {
        game->load_game->nb_save = 1;
        launch_save(game);
    }
    return (0);
}

int check_hitbox_save_two(game_t *game)
{
    if (game->load_game->save[1] == true) {
        if (check_hitbox_delete_button_two(game) == 1)
            return (0);
        check_hitbox_launch_save_two(game);
    }
    return (0);
}
