/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** audio_settings
*/

#include "rpg.h"

void audio_settings(game_t *game)
{
    sfSprite_setPosition(game->menu->background[3]->sprite,
    game->menu->background[3]->pos);
    sfSprite_setScale(game->menu->background[3]->sprite,
    game->menu->background[3]->scale);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->menu->background[3]->sprite, NULL);
    for (int i = 10; i != 14; i++)
        sfSprite_setTextureRect(game->menu->buttons[i]->sprite->sprite,
        game->menu->buttons[i]->sprite->rect);
    for (int i = 10; i != 16; i++)
        display_button(game->menu->buttons[i], game->game_info->window);
}
