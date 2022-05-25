/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** free_game
*/

#include "rpg.h"

void free_sound(game_t *game)
{
    sfSound_stop(game->audio->ak_sound);
    sfSound_stop(game->audio->eat_sound);
    sfSound_stop(game->audio->zombie);
    sfSound_destroy(game->audio->ak_sound);
    sfSound_destroy(game->audio->eat_sound);
    sfSound_destroy(game->audio->zombie);
}

void free_music(game_t *game)
{
    sfMusic_stop(game->audio->boss_fight);
    sfMusic_stop(game->audio->classic_fight);
    sfMusic_stop(game->audio->intro);
    sfMusic_stop(game->audio->menu_music);
    sfMusic_stop(game->audio->night_music);
    sfMusic_destroy(game->audio->boss_fight);
    sfMusic_destroy(game->audio->classic_fight);
    sfMusic_destroy(game->audio->intro);
    sfMusic_destroy(game->audio->menu_music);
    sfMusic_destroy(game->audio->night_music);
}

void free_all(game_t *game)
{
    free(game->game_info->scene);
    free(game->game_info);
    free(game);
}
