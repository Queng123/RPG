/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** init_game_bar
*/

#include "rpg.h"

void init_game_bar(game_t *game)
{
    game->gameplay->background[0] = build_bg("assets/game/hearth.png");
    game->gameplay->background[0]->pos = (sfVector2f) {170, 10};
    game->gameplay->background[0]->scale = (sfVector2f) {0.1, 0.1};
    game->gameplay->background[1] = build_bg("assets/game/eclair.png");
    game->gameplay->background[1]->pos = (sfVector2f) {156, 80};
    game->gameplay->background[1]->scale = (sfVector2f) {0.5, 0.5};
}
