/*
** EPITECH PROJECT, 2022
** display_save_two.c
** File description:
** function that display save two
*/

#include "rpg.h"

int display_save_two(game_t *game)
{
    if (game->load_game->save[1] == false) {
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_empty[1].spr, NULL);
    } else {
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_full[1].spr, NULL);
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_charact[1].spr, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->save_charact[1].name->text, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->day[1]->text, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->time[1]->text, NULL);
    }
    return (0);
}
