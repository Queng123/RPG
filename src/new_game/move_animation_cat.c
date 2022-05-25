/*
** EPITECH PROJECT, 2022
** move_animation_cat.c
** File description:
** move_animation_cat
*/

#include "rpg.h"

int move_animation_cat(game_t *game)
{
    game->new_game->cat.time = sfClock_restart(game->new_game->cat.clock);
    game->new_game->cat.total_time += game->new_game->cat.time.microseconds;
    if (game->new_game->cat.total_time >= 400000) {
        game->new_game->cat.rect.left += 205;
        game->new_game->cat.total_time -= 400000;
    }
    if (game->new_game->cat.rect.left > 3486)
        game->new_game->cat.rect.left = 0;
    sfSprite_setTextureRect(game->new_game->cat.spr, game->new_game->cat.rect);
    return (0);
}
