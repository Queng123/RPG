/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game
*/

#include "rpg.h"

int init_scene(game_t *game)
{
    game->game_info->scene = malloc(sizeof(scene_t));
    if (game->game_info->scene == NULL)
        return (ERROR);
    game->game_info->scene->actual_scene = MENU;
    game->game_info->scene->previous_scene = MENU;
    game->game_info->scene->actual_save = SAVE_1;
    game->game_info->scene->actual_menu_scene = MAIN_MENU;
    game->game_info->scene->previous_menu_scene = MAIN_MENU;
    game->game_info->scene->actual_game_scene = GAMEPLAY;
    game->game_info->scene->previous_game_scene = GAMEPLAY;
    game->game_info->scene->actual_how_to_play_scene = LOBBY;
    game->game_info->scene->previous_how_to_play_scene = LOBBY;
    game->game_info->scene->options_scene = HOW_TO_PLAY;
    game->game_info->scene->tablet_scene = PLAYER_INFO;
    return (SUCCESS);
}

void init_command(game_t *game)
{
    game->game_info->commands[0] = sfKeyZ;
    game->game_info->commands[1] = sfKeyS;
    game->game_info->commands[2] = sfKeyQ;
    game->game_info->commands[3] = sfKeyD;
    game->game_info->commands[4] = sfKeyLShift;
    game->game_info->commands[5] = sfKeyI;
    game->game_info->commands[6] = sfKeyE;
    game->game_info->commands[7] = sfKeyA;
    game->game_info->commands[8] = sfKeyM;
}

int init_basic(game_t *game)
{
    game->game_info = malloc(sizeof(info_t));
    if (game->game_info == NULL)
        return (ERROR);
    init_command(game);
    game->game_info->mode.bitsPerPixel = 32;
    game->game_info->mode.height = 1080;
    game->game_info->mode.width = 1920;
    game->game_info->window = sfRenderWindow_create(game->game_info->mode,
    "my_rpg", sfResize | sfClose, NULL);
    if (game->game_info->window == NULL)
        return (ERROR);
    game->game_info->fps = 60;
    game->game_info->sound_on = 1;
    game->game_info->music_on = 1;
    game->game_info->particles_on = 1;
    game->game_info->screen_size = BIG_SCREEN;
    game->game_info->volume_music = 100;
    game->game_info->volume_sound = 100;
    game->game_info->window_size = (sfVector2u) {1920, 1080};
    return (SUCCESS);
}

int initialize_var(game_t *game)
{
    if (init_basic(game) == ERROR || init_scene(game) == ERROR ||
    init_menu(game) == ERROR || init_intro(game) == ERROR
    || init_boss(game) == ERROR || init_howtwoplay(game) == ERROR)
        return (ERROR);
    build_game(game);
    return (SUCCESS);
}
