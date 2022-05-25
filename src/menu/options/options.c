/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** options
*/

#include "rpg.h"

void display_reseau(game_t *game)
{
    sfSprite_setPosition(game->menu->background[8]->sprite,
    game->menu->background[8]->pos);
    sfSprite_setScale(game->menu->background[8]->sprite,
    game->menu->background[8]->scale);
    sfSprite_setTextureRect(game->menu->background[8]->sprite,
    game->menu->background[8]->rect);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->menu->background[8]->sprite, NULL);
}

void display_colored_button(game_t *game)
{
    sfSprite_setPosition(game->menu->background[5]->sprite,
    game->menu->background[5]->pos);
    sfSprite_setScale(game->menu->background[5]->sprite,
    game->menu->background[5]->scale);
    sfSprite_setTextureRect(game->menu->background[5]->sprite,
    game->menu->background[5]->rect);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->menu->background[5]->sprite, NULL);
    while (game->menu->options_clock->seconds >= 0.8) {
        game->menu->options_clock->seconds -= 0.8;
        game->menu->background[5]->rect.left += 21;
        if (game->menu->background[5]->rect.left == (21 * 7))
            game->menu->background[5]->rect.left = 0;
        game->menu->background[8]->rect.left += 24;
        if (game->menu->background[8]->rect.left == (2400))
            game->menu->background[8]->rect.left = 0;
    }
}

void display_options_menu(game_t *game)
{
    display_bg(game->menu->background[1], game->game_info->window);
    display_bg(game->menu->background[2], game->game_info->window);
}

void display_options(game_t *game)
{
    int arg_list[] = {HOW_TO_PLAY, CONTROLS, VIDEO, AUDIO, -1};
    void (*options_scene[9])(game_t *game) = {display_help, choose_controls,
    video_settings, audio_settings};

    for (int i = 0; arg_list[i] != -1; i++)
        if ((int)game->game_info->scene->options_scene == arg_list[i])
            (*options_scene[i])(game);
    display_options_menu(game);
    display_colored_button(game);
    display_reseau(game);
    for (int i = 4; i != 8; i++) {
        display_button(game->menu->buttons[i], game->game_info->window);
        if (game->menu->buttons[i]->status == 0)
            sfText_setColor(game->menu->buttons[i]->text->text, sfWhite);
        else
            sfText_setColor(game->menu->buttons[i]->text->text, sfBlack);
    }
}
