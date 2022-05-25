/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** video_event
*/

#include "rpg.h"

int open_fps_option(game_t *game, sfVector2f click_pos)
{
    if (game->menu->show_size == 1)
        return (1);
    if (button_is_clicked(game->menu->buttons[20], click_pos) == 1 &&
    game->menu->show_fps == 0) {
        game->menu->show_fps = 1;
        game->menu->background[6]->rect.height = 100;
        return (1);
    }
    if (button_is_clicked(game->menu->buttons[21], click_pos) == 1) {
        game->menu->show_fps = (game->menu->show_fps == 1) ? 0 : 1;
        game->menu->background[6]->rect.height = 100;
        return (1);
    }
    return (0);
}

void change_rect(game_t *game)
{
    game->menu->show_fps = 0;
    game->menu->background[6]->rect.height = 100;
}

void is_max_fps(game_t *game)
{
    if (game->game_info->fps == 120) {
        game->menu->buttons[20]->text->pos = (sfVector2f) {955, 380};
    } else {
        game->menu->buttons[20]->text->pos = (sfVector2f) {965, 380};
    }
}

void choose_fps(game_t *game, sfVector2f click_pos)
{
    if (button_is_clicked(game->menu->buttons[22], click_pos) == 1) {
        game->game_info->fps = 30;
        change_rect(game);
    }
    if (button_is_clicked(game->menu->buttons[23], click_pos) == 1) {
        game->game_info->fps = 60;
        change_rect(game);
    }
    if (button_is_clicked(game->menu->buttons[24], click_pos) == 1) {
        game->game_info->fps = 90;
        change_rect(game);
    }
    if (button_is_clicked(game->menu->buttons[25], click_pos) == 1) {
        game->game_info->fps = 120;
        change_rect(game);
    }
    is_max_fps(game);
}

void manage_video_mouse_released(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f) {event.x, event.y};

    if (game->game_info->scene->actual_scene == MENU &&
    game->game_info->scene->actual_menu_scene == OPTIONS &&
    game->game_info->scene->options_scene == VIDEO) {
        if (button_is_clicked(game->menu->buttons[26], click_pos) == 1 &&
        game->menu->show_fps == 0 && game->menu->show_size == 0) {
            game->game_info->particles_on = (game->game_info->particles_on == 1)
            ? 0 : 1;
            game->menu->buttons[26]->sprite->rect.top =
            (game->menu->buttons[26]->sprite->rect.top == 256) ? 0 : 256;
        }
        if (game->menu->show_fps == 0)
            manage_size_settings(game, click_pos);
        if (open_fps_option(game, click_pos) == 1 || game->menu->show_fps == 0)
            return;
        choose_fps(game, click_pos);
    }
}
