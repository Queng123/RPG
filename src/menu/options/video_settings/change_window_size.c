/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** change_window_size
*/

#include "rpg.h"

void change_rect_size(game_t *game)
{
    game->menu->show_size = 0;
    game->menu->background[7]->rect.height = 100;
}

void change_for_full_screen(game_t *game, sfVector2f click_pos)
{
    if (button_is_clicked(game->menu->buttons[29], click_pos) == 1) {
        if (game->game_info->screen_size == FULL_SCREEN)
            return;
        game->game_info->screen_size = FULL_SCREEN;
        sfRenderWindow_destroy(game->game_info->window);
        game->game_info->mode.bitsPerPixel = 32;
        game->game_info->mode.height = 1080;
        game->game_info->mode.width = 1920;
        game->game_info->window = sfRenderWindow_create(game->game_info->mode,
        "my_rpg", sfFullscreen, NULL);
        game->game_info->window_size = (sfVector2u) {1920, 1080};
        change_rect_size(game);
    }
}

void change_for_big_screen(game_t *game, sfVector2f click_pos)
{
    if (button_is_clicked(game->menu->buttons[30], click_pos) == 1) {
        if (game->game_info->screen_size == BIG_SCREEN)
            return;
        game->game_info->screen_size = BIG_SCREEN;
        sfRenderWindow_destroy(game->game_info->window);
        game->game_info->mode.bitsPerPixel = 32;
        game->game_info->mode.height = 1080;
        game->game_info->mode.width = 1920;
        game->game_info->window = sfRenderWindow_create(game->game_info->mode,
        "my_rpg", sfResize | sfClose, NULL);
        game->game_info->window_size = (sfVector2u) {1920, 1080};
        change_rect_size(game);
    }
}
