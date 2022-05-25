/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** handle_end_musique
*/

#include "rpg.h"

void close_filestream(game_t *game)
{
    sfMusic_pause(game->audio->boss_fight);
    sfMusic_pause(game->audio->classic_fight);
    sfMusic_pause(game->audio->menu_music);
    sfMusic_pause(game->audio->night_music);
    sfMusic_stop(game->audio->boss_fight);
    sfMusic_stop(game->audio->classic_fight);
    sfMusic_stop(game->audio->menu_music);
    sfMusic_stop(game->audio->night_music);
}
