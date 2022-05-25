/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** update_sound
*/

#include "gameplay.h"

void update_sound(game_t *game, int volume)
{
    sfSound_setVolume(game->audio->ak_sound, volume);
    sfSound_setVolume(game->audio->eat_sound, volume);
    sfSound_setVolume(game->audio->zombie, volume);
}

void update_musique(game_t *game, int volume)
{
    sfMusic_setVolume(game->audio->boss_fight, volume);
    sfMusic_setVolume(game->audio->menu_music, volume);
    sfMusic_setVolume(game->audio->classic_fight, volume);
    sfMusic_setVolume(game->audio->night_music, volume);
    sfMusic_setVolume(game->audio->intro, volume);
}

void update_sound_parameters(game_t *game)
{
    if (game->game_info->sound_on == 1) {
        update_sound(game, game->game_info->volume_sound);
    }
    if (game->game_info->music_on == 1) {
        update_musique(game, game->game_info->volume_music);
    }
}

void update_sound_status(game_t *game)
{
    if (game->game_info->sound_on == 0) {
        update_sound(game, 0);
    }
    if (game->game_info->music_on == 0) {
        update_musique(game, 0);
    }
    update_sound_parameters(game);
}

void reset_musique(game_t *game)
{
    sfMusic_stop(game->audio->boss_fight);
    sfMusic_stop(game->audio->classic_fight);
    sfMusic_stop(game->audio->menu_music);
    sfMusic_stop(game->audio->night_music);
    sfMusic_stop(game->audio->intro);
}
