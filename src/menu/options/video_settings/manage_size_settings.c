/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** manage_size_settings
*/

#include "rpg.h"

int open_size_option(game_t *game, sfVector2f click_pos)
{
    if (button_is_clicked(game->menu->buttons[27], click_pos) == 1 &&
    game->menu->show_size == 0) {
        game->menu->show_size = 1;
        game->menu->background[7]->rect.height = 100;
        return (1);
    }
    if (button_is_clicked(game->menu->buttons[28], click_pos) == 1) {
        game->menu->show_size = (game->menu->show_size == 1) ? 0 : 1;
        game->menu->background[7]->rect.height = 100;
        return (1);
    }
    return (0);
}

void is_big_size(game_t *game)
{
    if (game->game_info->screen_size == BIG_SCREEN) {
        game->menu->buttons[27]->text->pos = (sfVector2f) {845, 605};
    } else {
        game->menu->buttons[27]->text->pos = (sfVector2f) {865, 605};
    }
}

void choose_size(game_t *game, sfVector2f click_pos)
{
    change_for_full_screen(game, click_pos);
    change_for_big_screen(game, click_pos);
    is_big_size(game);
}

void manage_size_settings(game_t *game, sfVector2f click_pos)
{
    if (open_size_option(game, click_pos) == 1)
        return;
    if (game->menu->show_size == 0)
        return;
    choose_size(game, click_pos);
}
