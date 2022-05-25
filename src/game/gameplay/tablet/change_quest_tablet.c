/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** change_quest_tablet
*/

#include "rpg.h"

void change_strenght(game_t *game)
{
    if (game->gameplay->tablet->button[8]->status == 1)
        game->player->stat->strength += 5;
    if (game->gameplay->tablet->button[9]->status == 1)
        game->player->stat->strength += 5;
}

void change_statistic(game_t *game)
{
    if (game->gameplay->tablet->button[4]->status == 1)
        game->player->stamina_max = 250;
    if (game->gameplay->tablet->button[5]->status == 1)
        game->player->stamina_max = 300;
    if (game->gameplay->tablet->button[6]->status == 1)
        game->player->health->max_score = 150;
    if (game->gameplay->tablet->button[7]->status == 1)
        game->player->health->max_score = 200;
    change_strenght(game);
}

void change_last_quest(game_t *game)
{
    if (game->quest->mayor_talk == -2 &&
    game->quest->current_level_quest == 2) {
        game->gameplay->tablet->background[5]->rect.height = 400;
        game->gameplay->tablet->background[6]->rect.height = 330;
    }
    if (game->quest->mayor_talk == 1 && game->quest->current_level_quest == 2) {
        game->gameplay->tablet->background[5]->rect.height = 470;
        game->gameplay->tablet->background[6]->rect.height = 400;
        game->quest->mayor_talk = -3;
    }
    if (game->quest->mayor_talk == -3 &&
    game->quest->current_level_quest == 3) {
        game->gameplay->tablet->background[5]->rect.height = 540;
        game->gameplay->tablet->background[6]->rect.height = 470;
    }
}

void change_quest_tablet(game_t *game)
{
    if (game->quest->current_level_quest == 0) {
        game->gameplay->tablet->background[5]->rect.height = 190;
        game->gameplay->tablet->background[6]->rect.height = 120;
        game->quest->mayor_talk = -1;
    }
    if (game->quest->mayor_talk == -1 &&
    game->quest->current_level_quest == 1) {
        game->gameplay->tablet->background[5]->rect.height = 260;
        game->gameplay->tablet->background[6]->rect.height = 190;
    }
    if (game->quest->mayor_talk == 1 && game->quest->current_level_quest == 1) {
        game->gameplay->tablet->background[5]->rect.height = 330;
        game->gameplay->tablet->background[6]->rect.height = 260;
        game->quest->mayor_talk = -2;
    }
    change_last_quest(game);
}
