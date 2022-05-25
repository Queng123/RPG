/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** game_intro
*/

#include "rpg.h"

void management_of_life_player(game_t *game)
{
    if (game->boss_s->life_player == 3) {
        game->boss_s->background[9]->rect = (sfIntRect){0, 0, 288, 288};
        display_heart_player(game);
    }
    if (game->boss_s->life_player == 2) {
        game->boss_s->background[9]->rect = (sfIntRect){297, 0, 288, 288};
        display_heart_player(game);
    }
    if (game->boss_s->life_player == 1) {
        game->boss_s->background[9]->rect = (sfIntRect){579, 0, 288, 288};
        display_heart_player(game);
    }
}

void management_of_life_boss(game_t *game)
{
    if (game->boss_s->life_boss == 3) {
        game->boss_s->background[10]->rect = (sfIntRect){0, 0, 288, 288};
        display_heart_boss(game);
    }
    if (game->boss_s->life_boss == 2) {
        game->boss_s->background[10]->rect = (sfIntRect){297, 0, 288, 288};
        display_heart_boss(game);
    }
    if (game->boss_s->life_boss == 1) {
        game->boss_s->background[10]->rect = (sfIntRect){579, 0, 288, 288};
        display_heart_boss(game);
    }
}

void display_frame_two(game_t *game)
{
    sfRenderWindow_drawSprite(game->game_info->window,
    game->boss_s->background[0]->sprite, NULL);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    management_of_life_player(game);
    management_of_life_boss(game);
}

void frame_two(game_t *game)
{

    if (game->boss_s->frame_boss == 2) {
        display_frame_two(game);
        systeme_fight(game);
    }
}
