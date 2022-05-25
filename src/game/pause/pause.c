/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** pause
*/

#include "rpg.h"

void manage_pause_buttons(game_t *game, sfMouseButtonEvent event)
{
    sfVector2f click_pos = (sfVector2f) {event.x, event.y};

    if (button_is_clicked(game->gameplay->pause->button[0], click_pos) == 1) {
        game->game_info->scene->actual_scene = MENU;
        game->game_info->scene->actual_menu_scene = MAIN_MENU;
        game->gameplay->pause->display = false;
        save_game(game);
        game->load_game->load_save = -1;
    }
    if (button_is_clicked(game->gameplay->pause->button[1], click_pos) == 1) {
        game->game_info->scene->actual_scene = MENU;
        game->game_info->scene->previous_scene = GAME;
        game->game_info->scene->actual_menu_scene = OPTIONS;
    }
    if (button_is_clicked(game->gameplay->pause->button[2], click_pos) == 1)
        game->gameplay->pause->display = false;
}

void handle_pause(game_t *game)
{
    if (game->event.key.code == sfKeyEscape &&
    game->game_info->scene->actual_scene == GAME &&
    game->game_info->scene->actual_game_scene == GAMEPLAY) {
        game->gameplay->pause->display =
        (game->gameplay->pause->display == true) ? false : true;
    }
}

void display_pause(game_t *game)
{
    display_bg(game->gameplay->pause->background, game->game_info->window);
    for (int i = 0; i != 3; i++) {
        display_button(game->gameplay->pause->button[i],
        game->game_info->window);
    }
}
