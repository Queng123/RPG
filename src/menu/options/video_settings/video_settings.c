/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** video_settings
*/

#include "rpg.h"

void display_choose_fps(game_t *game)
{
    if (game->menu->background[6]->rect.height <= 390)
        game->menu->background[6]->rect.height +=
        (game->menu->fps_clock->time.microseconds / 1000000.0f) * 1500;
    display_bg(game->menu->background[6], game->game_info->window);
}

void display_choose_size(game_t *game)
{
    if (game->menu->background[7]->rect.height <= 190)
        game->menu->background[7]->rect.height +=
        (game->menu->fps_clock->time.microseconds / 1000000.0f) * 1500;
    display_bg(game->menu->background[7], game->game_info->window);
}

void choose_fps_sprite(game_t *game)
{
    if (game->game_info->fps == 30)
        game->menu->background[6]->rect.left = 0;
    if (game->game_info->fps == 60)
        game->menu->background[6]->rect.left = 500;
    if (game->game_info->fps == 90)
        game->menu->background[6]->rect.left = 1000;
    if (game->game_info->fps == 120)
        game->menu->background[6]->rect.left = 1500;
}

void choose_size_sprite(game_t *game)
{
    if (game->game_info->screen_size == FULL_SCREEN) {
        game->menu->background[7]->rect.left = 0;
        game->menu->buttons[27]->text->str = "Full screen";
    }
    if (game->game_info->screen_size == BIG_SCREEN) {
        game->menu->background[7]->rect.left = 700;
        game->menu->buttons[27]->text->str = "1920 x 1080";
    }
    if (game->game_info->screen_size == MEDIUM_SCREEN) {
        game->menu->background[7]->rect.left = 1400;
        game->menu->buttons[27]->text->str = "1600 x 900";
    }
    if (game->game_info->screen_size == SMALL_SCREEN) {
        game->menu->background[7]->rect.left = 2100;
        game->menu->buttons[27]->text->str = "1280 x 720";
    }
}

void video_settings(game_t *game)
{
    choose_fps_sprite(game);
    choose_size_sprite(game);
    game->menu->buttons[20]->text->str = int_to_char(game->game_info->fps);
    sfSprite_setTextureRect(game->menu->background[6]->sprite,
    game->menu->background[6]->rect);
    sfSprite_setTextureRect(game->menu->background[7]->sprite,
    game->menu->background[7]->rect);
    sfSprite_setTextureRect(game->menu->buttons[26]->sprite->sprite,
    game->menu->buttons[26]->sprite->rect);
    display_bg(game->menu->background[4], game->game_info->window);
    display_button(game->menu->buttons[20], game->game_info->window);
    display_button(game->menu->buttons[27], game->game_info->window);
    display_button(game->menu->buttons[26], game->game_info->window);
    if (game->menu->show_size == 1)
        display_choose_size(game);
    if (game->menu->show_fps == 1)
        display_choose_fps(game);
    display_button(game->menu->buttons[21], game->game_info->window);
    display_button(game->menu->buttons[28], game->game_info->window);
}
