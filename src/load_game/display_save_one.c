/*
** EPITECH PROJECT, 2022
** display_save_one.c
** File description:
** function that display save one
*/

#include "rpg.h"

int display_save_one(game_t *game)
{
    if (game->load_game->save[0] == false) {
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_empty[0].spr, NULL);
    } else {
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_full[0].spr, NULL);
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_charact[0].spr, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->save_charact[0].name->text, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->day[0]->text, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->time[0]->text, NULL);
    }
    return (0);
}
