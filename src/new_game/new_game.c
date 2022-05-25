/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** new_game
*/

#include "rpg.h"

void start_new_game(game_t *game)
{
    move_animation_cat(game);
    move_animation_reseau_charger(game);
    display_bg(game->menu->background[1], game->game_info->window);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->new_game->class_menu[game->new_game->class].spr,
    NULL);
    sfRenderWindow_drawSprite(game->game_info->window, game->new_game->cat.spr
    , NULL);
    display_colored_button(game);
    display_reseau(game);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->new_game->character[game->new_game->class * 5
    + game->new_game->color].spr, NULL);
}
