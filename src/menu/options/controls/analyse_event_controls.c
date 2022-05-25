/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** analyse_event_controls
*/

#include "rpg.h"

void analyse_control_wheel(sfMouseWheelEvent event, game_t *game)
{
    if (!(game->game_info->scene->actual_scene == MENU &&
        game->game_info->scene->actual_menu_scene == OPTIONS &&
        game->game_info->scene->options_scene == CONTROLS))
        return;
    if (game->menu->background[9]->rect.top < 2390 && event.delta < 0) {
        game->menu->background[10]->pos.y += 10;
        game->menu->background[9]->rect.top += 53;
        for (int i = 33; i != 42; i++) {
            game->menu->buttons[i]->sprite->pos.y -= 34.5;
        }
    } else if (game->menu->background[9]->rect.top > 0 && event.delta > 0) {
        game->menu->background[9]->rect.top -= 53;
        game->menu->background[10]->pos.y -= 10;
        for (int i = 33; i != 42; i++) {
            game->menu->buttons[i]->sprite->pos.y += 34.5;
        }
    }
}

void manage_control_mouse_released(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f){event.x, event.y};

    if (!(game->game_info->scene->actual_scene == MENU &&
        game->game_info->scene->actual_menu_scene == OPTIONS &&
        game->game_info->scene->options_scene == CONTROLS))
        return;
    for (int i = 33; i != 42; i++) {
        if (game->menu->buttons[i]->sprite->pos.y <= 225 ||
            game->menu->buttons[i]->sprite->pos.y >= 850)
            continue;
        if (button_is_clicked(game->menu->buttons[i], click_pos) == 1)
            game->menu->buttons[i]->status = 1;
        else
            game->menu->buttons[i]->status = 0;
    }
}

int key_is_already_take(sfKeyCode code, sfKeyCode *commands)
{
    for (int i = 0; i != 9; i++)
        if (commands[i] == code)
            return (1);
    return (0);
}

void analyse_control_key(sfKeyEvent event, game_t *game)
{
    if (!(game->game_info->scene->actual_scene == MENU &&
        game->game_info->scene->actual_menu_scene == OPTIONS &&
        game->game_info->scene->options_scene == CONTROLS))
        return;
    if (event.code == sfKeyUnknown || event.code == sfKeyEscape ||
        key_is_already_take(event.code, game->game_info->commands) == 1) {
        game->menu->buttons[42]->text->str = "Please press a valid key";
        return;
    }
    for (int i = 33; i != 42; i++) {
        if (game->menu->buttons[i]->status == 1) {
            game->menu->buttons[i]->sprite->rect.left = (event.code % 10) * 193;
            game->menu->buttons[i]->sprite->rect.top = (event.code / 10) * 157;
            game->menu->buttons[i]->status = 0;
            game->game_info->commands[i - 33] = event.code;
            game->menu->buttons[42]->text->str = "Press any key to assign it";
        }
    }
}
