/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** analyse_event_menu
*/

#include "rpg.h"

void manage_option_button(game_t *game, sfVector2f click_pos)
{
    if (text_is_clicked(game->menu->buttons[2], click_pos) == 1) {
        game->game_info->scene->actual_menu_scene = OPTIONS;
        game->game_info->scene->previous_menu_scene = MAIN_MENU;
        game->game_info->scene->previous_scene = MENU;
        sfText_setColor(game->menu->buttons[2]->text->text, sfWhite);
        game->menu->show_fps = 0;
        game->menu->show_size = 0;
    }
    if (text_is_clicked(game->menu->buttons[3], click_pos) == 1)
        sfRenderWindow_close(game->game_info->window);
}

int set_save_game(game_t *game, sfVector2f click_pos)
{
    if (text_is_clicked(game->menu->buttons[0], click_pos) == 1) {
        if (game->load_game->save[0] == true
            && game->load_game->save[1] == true
            && game->load_game->save[2] == true)
            return (1);
        game->game_info->scene->actual_scene = NEW_GAME;
        active_default_value_new_game(game);
        game->game_info->scene->previous_scene = MENU;
        sfText_setColor(game->menu->buttons[0]->text->text, sfWhite);
    }
    return (0);
}

void manage_menu_mouse_released(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f){event.x, event.y};

    if (game->game_info->scene->actual_scene == MENU &&
        game->game_info->scene->actual_menu_scene == MAIN_MENU) {
        if (set_save_game(game, click_pos) == 1)
            return;
        if (text_is_clicked(game->menu->buttons[1], click_pos) == 1) {
            game->game_info->scene->actual_scene = LOAD_GAME;
            active_default_value_load_game(game);
            game->game_info->scene->previous_scene = MENU;
            sfText_setColor(game->menu->buttons[1]->text->text, sfWhite);
        }
        manage_option_button(game, click_pos);
    }
}

void analyse_event_menu_next_part(game_t *game)
{
    if (game->event.type == sfEvtMouseWheelMoved) {
        analyse_control_wheel(game->event.mouseWheel, game);
    }
    if (game->event.type == sfEvtKeyPressed)
        analyse_control_key(game->event.key, game);
}

void analyse_event_menu(game_t *game)
{
    if (game->event.type == sfEvtMouseButtonPressed) {
        manage_menu_mouse_click(game->event.mouseButton, game);
    }
    if (game->event.type == sfEvtMouseMoved) {
        manage_menu_movement(game->event.mouseMove, game);
        manage_handle_skill_tree(game->event.mouseMove, game);
    }
    if (game->event.type == sfEvtMouseButtonReleased) {
        manage_menu_mouse_released(game->event.mouseButton, game);
        manage_options_mouse_released(game->event.mouseButton, game);
        manage_audio_mouse_released(game->event.mouseButton, game);
        manage_video_mouse_released(game->event.mouseButton, game);
        manage_control_mouse_released(game->event.mouseButton, game);
        analyse_how_to_play_event(game->event.mouseButton, game);
    }
    analyse_event_menu_next_part(game);
}
