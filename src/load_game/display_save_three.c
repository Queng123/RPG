/*
** EPITECH PROJECT, 2022
** display_save_three.c
** File description:
** function that display save three
*/

#include "rpg.h"

int display_save_three(game_t *game)
{
    if (game->load_game->save[2] == false) {
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_empty[2].spr, NULL);
    } else {
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_full[2].spr, NULL);
        sfRenderWindow_drawSprite(game->game_info->window,
        game->load_game->save_charact[2].spr, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->save_charact[2].name->text, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->day[2]->text, NULL);
        sfRenderWindow_drawText(game->game_info->window,
        game->load_game->time[2]->text, NULL);
    }
    return (0);
}
