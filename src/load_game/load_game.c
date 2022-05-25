/*
** EPITECH PROJECT, 2022
** load_game.c
** File description:
** function main of load_game part
*/

#include "rpg.h"

int display_background_load_game(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->menu->background[11]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->load_game->support_save.spr, NULL);
    return (0);
}

void start_load_game(game_t *game)
{
    move_animation_cat(game);
    display_background_load_game(game);
    display_save_one(game);
    display_save_two(game);
    display_save_three(game);
    if (game->load_game->delete == true)
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->delete_save.spr, NULL);
    sfRenderWindow_drawSprite(game->game_info->window, game->new_game->cat.spr
    , NULL);
}
