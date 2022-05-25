/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** analyse_options_event
*/

#include "rpg.h"

void manage_back_to_menu_scene(game_t *game, sfVector2f click_pos)
{
    if (button_is_clicked(game->menu->buttons[8], click_pos) == 1) {
        game->game_info->scene->actual_scene =
        game->game_info->scene->previous_scene;
        game->game_info->scene->actual_menu_scene =
        game->game_info->scene->previous_menu_scene;
        game->game_info->scene->previous_menu_scene = OPTIONS;
    }
    if (button_is_clicked(game->menu->buttons[9], click_pos) == 1) {
        game->game_info->scene->actual_menu_scene = MAIN_MENU;
        game->game_info->scene->previous_menu_scene = OPTIONS;
        if (game->game_info->scene->previous_scene == GAME) {
            save_game(game);
            game->load_game->load_save = -1;
        }
    }
}

void manage_button_video(game_t *game, sfVector2f click_pos)
{
    if (text_is_clicked(game->menu->buttons[6], click_pos) == 1) {
        game->game_info->scene->options_scene = AUDIO;
        game->menu->buttons[4]->status = 1;
        game->menu->buttons[5]->status = 1;
        game->menu->buttons[6]->status = 0;
        game->menu->buttons[7]->status = 1;
    }
    if (text_is_clicked(game->menu->buttons[7], click_pos) == 1) {
        game->game_info->scene->options_scene = VIDEO;
        game->menu->buttons[4]->status = 1;
        game->menu->buttons[5]->status = 1;
        game->menu->buttons[6]->status = 1;
        game->menu->buttons[7]->status = 0;
        game->menu->show_fps = 0;
        game->menu->show_size = 0;
    }
    manage_back_to_menu_scene(game, click_pos);
}

void manage_options_mouse_released(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f){event.x, event.y};

    if (game->game_info->scene->actual_scene == MENU &&
        game->game_info->scene->actual_menu_scene == OPTIONS) {
        if (text_is_clicked(game->menu->buttons[4], click_pos) == 1) {
            game->game_info->scene->options_scene = HOW_TO_PLAY;
            game->menu->buttons[4]->status = 0;
            game->menu->buttons[5]->status = 1;
            game->menu->buttons[6]->status = 1;
            game->menu->buttons[7]->status = 1;
        }
        if (text_is_clicked(game->menu->buttons[5], click_pos) == 1) {
            game->game_info->scene->options_scene = CONTROLS;
            game->menu->buttons[4]->status = 1;
            game->menu->buttons[5]->status = 0;
            game->menu->buttons[6]->status = 1;
            game->menu->buttons[7]->status = 1;
        }
        manage_button_video(game, click_pos);
    }
}
