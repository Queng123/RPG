/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** play_song
*/

#include "gameplay.h"

int is_it_game(game_t *game)
{
    if (game->game_info->scene->actual_game_scene == GAMEPLAY &&
    game->game_info->scene->actual_menu_scene != LOAD_SAVE
        && (game->game_info->scene->actual_scene != MENU &&
        game->game_info->scene->actual_scene != NEW_GAME &&
        game->game_info->scene->actual_scene != LOAD_GAME)) {
        return (1);
    }
    return (0);
}

int is_it_menu(game_t *game)
{
    if (game->game_info->scene->actual_game_scene == INTRO
    || game->game_info->scene->actual_scene == MENU ||
    game->game_info->scene->actual_scene == NEW_GAME ||
    game->game_info->scene->actual_scene == LOAD_GAME) {
        return (1);
    }
    return (0);
}

int is_night(int time)
{
    int m = (time - (1440 * (time / 1440))) / 60;

    if (m < 6 || m >= 22) {
        return (0);
    }
    return (1);
}

void play_song_gameplay(game_t *game)
{
    if (is_night(game->gameplay->time) == 0 && game->audio->is_played != 3) {
        reset_musique(game);
        sfMusic_play(game->audio->night_music);
        game->audio->is_played = 3;
    }
    if (is_night(game->gameplay->time) == 1 && game->audio->is_played != 2) {
        reset_musique(game);
        sfMusic_play(game->audio->menu_music);
        game->audio->is_played = 2;
    }
}

void play_song(game_t *game)
{
    if (is_it_game(game)) {
        play_song_gameplay(game);
    }
    if (is_it_menu(game)) {
        if (game->audio->is_played != 1) {
            reset_musique(game);
            sfMusic_play(game->audio->intro);
            game->audio->is_played = 1;
        }
    }
    if (game->game_info->scene->actual_game_scene == BOSS) {
        if (game->audio->is_played != 4) {
            reset_musique(game);
            sfMusic_play(game->audio->boss_fight);
            game->audio->is_played = 4;
        }
    }
}
