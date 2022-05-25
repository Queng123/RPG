/*
** EPITECH PROJECT, 2022
** manage_menu_movement.c
** File description:
** manage_menu_movement
*/

#include "rpg.h"

void set_menu_button(game_t *game, int i)
{
    sfText_setColor(game->menu->buttons[i]->text->text, sfWhite);
    game->menu->buttons[i]->text->scale = (sfVector2f) {1.8, 1.8};
    game->menu->buttons[i]->status = 0;
}

void manage_menu_movement(sfMouseMoveEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f) {event.x, event.y};
    if (!(game->game_info->scene->actual_scene == MENU &&
        game->game_info->scene->actual_menu_scene == MAIN_MENU))
        return;
    for (int i = 0; i != 4; i++) {
        if (text_is_clicked(game->menu->buttons[i], click_pos) == 1 &&
            game->menu->buttons[i]->status == 0) {
            sfText_setColor(game->menu->buttons[i]->text->text, sfRed);
            game->menu->buttons[i]->text->scale = (sfVector2f) {2, 2};
        } else if (text_is_clicked(game->menu->buttons[i], click_pos) == 1 &&
            game->menu->buttons[i]->status == 1) {
            sfText_setColor(game->menu->buttons[i]->text->text, sfRed);
            game->menu->buttons[i]->text->scale = (sfVector2f) {1.6, 1.6};
        } else {
            set_menu_button(game, i);
        }
    }
}
