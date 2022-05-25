/*
** EPITECH PROJECT, 2021
** my_hunter.c
** File description:
** header
*/

#include "gameplay.h"

void destroy_all(game_t *game_s)
{
    destroy_sprite(game_s);
    destroy_tab_entitie(game_s->entitie);
    close_filestream(game_s);
    sfRenderWindow_destroy(game_s->game_info->window);
}
