/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** main_menu
*/

#include "rpg.h"

void display_background_menu(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->menu->background[11]->sprite, NULL);
}

void display_menu_buttons(game_t *game)
{
    for (int i = 0; i != 4; i++) {
        display_button(game->menu->buttons[i], game->game_info->window);
    }
}

void display_menu_arch(game_t *game)
{
    sfSprite_setPosition(game->menu->background[0]->sprite,
    game->menu->background[0]->pos);
    sfSprite_setTexture(game->menu->background[0]->sprite,
    game->menu->background[0]->texture, sfTrue);
    sfSprite_setScale(game->menu->background[0]->sprite,
    game->menu->background[0]->scale);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->menu->background[0]->sprite, NULL);
}

void display_main_menu(game_t *game)
{
    display_background_menu(game);
    display_menu_arch(game);
    display_menu_buttons(game);
}
