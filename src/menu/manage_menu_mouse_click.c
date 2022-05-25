/*
** EPITECH PROJECT, 2022
** manage_menu_mouse_click.c
** File description:
** manage_menu_mouse_click
*/

#include "rpg.h"

void manage_menu_mouse_click(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f){event.y, event.x};

    for (int i = 0; i != 4; i++) {
        if (text_is_clicked(game->menu->buttons[i], click_pos) == 1 &&
            game->game_info->scene->actual_scene == MENU &&
            game->game_info->scene->actual_menu_scene == MAIN_MENU) {
            game->menu->buttons[i]->text->scale = (sfVector2f) {1.6, 1.6};
            game->menu->buttons[i]->status = 1;
        } else {
            game->menu->buttons[i]->text->scale = (sfVector2f) {1.8, 1.8};
        }
    }
}
