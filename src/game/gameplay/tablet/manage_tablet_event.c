/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** manage_tablet_event
*/

#include "rpg.h"

void set_button(game_t *game, int i)
{
    for (int j = 0; j != 4; j++)
        game->gameplay->tablet->button[j]->status = 0;
    game->gameplay->tablet->button[i]->status = 1;
}

void click_tablet(game_t *game, sfMouseButtonEvent event)
{
    sfVector2f click_pos = (sfVector2f) {event.x, event.y};

    if (game->gameplay->tablet->display == false)
        return;
    for (int i = 0; i != 4; i++)
        if (button_is_clicked(game->gameplay->tablet->button[i],
        click_pos) == 1) {
            set_button(game, i);
            game->game_info->scene->tablet_scene = (enum_tablet) i;
        }
    if (game->game_info->scene->tablet_scene == SKILL_TREE)
        manage_skill_tree_buttons(game, click_pos);
}

void handle_tablet(game_t *game)
{
    if (game->event.key.code == game->game_info->commands[8] &&
    game->game_info->scene->actual_scene == GAME &&
    game->game_info->scene->actual_game_scene == GAMEPLAY) {
        game->gameplay->tablet->display =
        (game->gameplay->tablet->display == true) ? false : true;
        game->gameplay->tablet->screen_clock->seconds = 0;
        game->gameplay->tablet->background[2]->rect.left = 0;
    }
}
