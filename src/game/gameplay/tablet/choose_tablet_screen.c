/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** choose_tablet_screen
*/

#include "rpg.h"

void display_player_info(game_t *game)
{
    sfVector2f pos = set_pos(game, (sfVector2f) {170, 220});
    sfIntRect rect = game->player->obj->rect;
    sfIntRect rect_texture = {0, 0, 30, 32};

    game->gameplay->tablet->background[8]->pos = set_pos(game,
    (sfVector2f) {129, 99});
    display_bg(game->gameplay->tablet->background[8], game->game_info->window);
    sfSprite_setScale(game->player->obj->sprite, (sfVector2f) {8, 8});
    sfSprite_setTextureRect(game->player->obj->sprite, rect_texture);
    sfSprite_setPosition(game->player->obj->sprite, pos);
    sfRenderWindow_drawSprite(game->game_info->window,
    game->player->obj->sprite, NULL);
    sfSprite_setTextureRect(game->player->obj->sprite, rect);
    display_player_info_text(game);
}

void display_skill_tree(game_t *game)
{
    set_pos_skill_tree(game);
    display_bg(game->gameplay->tablet->background[7], game->game_info->window);
    for (int i = 4; i != 10; i++) {
        sfSprite_setTextureRect
        (game->gameplay->tablet->button[i]->sprite->sprite,
        game->gameplay->tablet->button[i]->sprite->rect);
        display_button(game->gameplay->tablet->button[i],
        game->game_info->window);
    }
    display_cost_and_points(game);
    change_statistic(game);
}

void display_map(game_t *game)
{
    display_mini_map(game);
}

void display_quest(game_t *game)
{
    for (int i = 4; i != 7; i++) {
        game->gameplay->tablet->background[i]->pos = set_pos(game,
        (sfVector2f) {129, 99});
        sfSprite_setTextureRect(game->gameplay->tablet->background[i]->sprite,
        game->gameplay->tablet->background[i]->rect);
    }
    change_quest_tablet(game);
    display_bg(game->gameplay->tablet->background[4], game->game_info->window);
    display_bg(game->gameplay->tablet->background[5], game->game_info->window);
    display_bg(game->gameplay->tablet->background[6], game->game_info->window);
}

void choose_tablet_screen(game_t *game)
{
    int arg_list[] = {PLAYER_INFO, SKILL_TREE, MAP, QUEST, -1};
    void (*game_scene[9])(game_t *game) = {display_player_info,
    display_skill_tree, display_map, display_quest};

    for (int i = 0; arg_list[i] != -1; i++) {
        if ((int)game->game_info->scene->tablet_scene == arg_list[i]) {
            (*game_scene[i])(game);
        }
    }
}
