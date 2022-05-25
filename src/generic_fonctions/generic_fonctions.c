/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** generic_fonctions
*/

#include "rpg.h"

int is_resizable(game_t *game)
{
    if (sfRenderWindow_getSize(game->game_info->window).x !=
    game->game_info->window_size.x ||
    sfRenderWindow_getSize(game->game_info->window).y !=
    game->game_info->window_size.y)
        return (1);
    return (0);
}

void display(game_t *game)
{
    int arg_list[] = {MENU, NEW_GAME, LOAD_GAME, GAME, -1};
    void (*p[9])(game_t *game) = {display_menu, start_new_game, start_load_game
    , display_game};

    sfRenderWindow_setFramerateLimit(game->game_info->window,
    game->game_info->fps);
    play_song(game);
    for (int i = 0; arg_list[i] != -1; i++) {
        if ((int)game->game_info->scene->actual_scene == arg_list[i]) {
            (*p[i])(game);
        }
    }
}

int my_rpg(void)
{
    game_t *game = malloc(sizeof(game_t));

    if (initialize_var(game) == ERROR)
        return (ERROR);
    while (sfRenderWindow_isOpen(game->game_info->window)) {
        display(game);
        sfRenderWindow_display(game->game_info->window);
        while (sfRenderWindow_pollEvent(game->game_info->window, &game->event))
            analyse_event(game->event, game);
        sfRenderWindow_clear(game->game_info->window, sfBlack);
    }
    free_sound(game);
    free_music(game);
    free_all(game);
    return (SUCCESS);
}
