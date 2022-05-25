/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** analyse_event
*/

#include "rpg.h"

void analyse_control_key_boss_qte(sfKeyEvent event, game_t *game)
{
    game->boss_s->background[3]->rect.left = (event.code % 10) * 193;
    game->boss_s->background[3]->rect.top = (event.code / 10) * 157;
}

void analyse_event_boss(game_t *game)
{
    if (game->boss_s->menu_boss == 1) {
        if (game->event.type == sfEvtKeyPressed) {
            game->boss_s->key_qte = game->event.key.code;
        }
    }
}
