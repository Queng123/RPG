/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** how2play
*/

#include "rpg.h"

void analyse_how_to_play_event(sfMouseButtonEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f) {event.x, event.y};

    if (game->game_info->scene->options_scene != HOW_TO_PLAY ||
        game->game_info->scene->actual_menu_scene != OPTIONS ||
        game->game_info->scene->actual_scene != MENU)
        return;
    if (button_is_clicked(game->howtwoplay_s->button[1], click_pos) == 0) {
        game->howtwoplay_s->scene += 1;
        if (game->howtwoplay_s->scene == 6)
            game->howtwoplay_s->scene = 0;
    }
    if (button_is_clicked(game->howtwoplay_s->button[0], click_pos) == 0) {
        game->howtwoplay_s->scene -= 1;
        if (game->howtwoplay_s->scene == -1)
            game->howtwoplay_s->scene = 5;
    }
}

void display_help(game_t *game)
{
    for (int i = 0; i != 2; i++)
        display_button(game->howtwoplay_s->button[i], game->game_info->window);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->howtwoplay_s->background[game->howtwoplay_s->scene]->sprite, NULL);
}
