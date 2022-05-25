/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_tablet
*/

#include "rpg.h"

sfVector2f set_pos(game_t *game, sfVector2f ratio)
{
    sfVector2f pos = {0, 0};

    pos.x = game->gameplay->tablet->background[0]->pos.x + (ratio.x * 0.8);
    pos.y = game->gameplay->tablet->background[0]->pos.y + (ratio.y * 0.8);
    return (pos);
}

void animate_active_button(game_t *game, int i)
{
    game->gameplay->tablet->button[i]->sprite->pos = set_pos(game,
    (sfVector2f) {370 + i * 130, 600});
    game->gameplay->tablet->background[3]->pos = set_pos(game,
    (sfVector2f) {370 + i * 130, 700});
}

void display_button_tablet(game_t *game)
{
    for (int i = 0; i != 4; i++) {
        if (game->gameplay->tablet->button[i]->status == 0)
            game->gameplay->tablet->button[i]->sprite->pos = set_pos(game,
            (sfVector2f) {370 + i * 130, 640});
        else
            animate_active_button(game, i);
    }
    game->gameplay->tablet->button[0]->text->pos = set_pos(game,
    (sfVector2f) {345, 730});
    game->gameplay->tablet->button[1]->text->pos = set_pos(game,
    (sfVector2f) {490, 730});
    game->gameplay->tablet->button[2]->text->pos = set_pos(game,
    (sfVector2f) {650, 730});
    game->gameplay->tablet->button[3]->text->pos = set_pos(game,
    (sfVector2f) {770, 730});
    for (int i = 0; i != 4; i++)
        display_button(game->gameplay->tablet->button[i],
        game->game_info->window);
    display_bg(game->gameplay->tablet->background[3],
    game->game_info->window);
}

void start_tablet(game_t *game)
{
    if (game->gameplay->tablet->background[2]->rect.left < 3804) {
        game->gameplay->tablet->background[2]->pos = set_pos(game,
        (sfVector2f) {129, 99});
        sfSprite_setTextureRect(game->gameplay->tablet->background[2]->sprite,
        game->gameplay->tablet->background[2]->rect);
        display_bg(game->gameplay->tablet->background[2],
        game->game_info->window);
        while (game->gameplay->tablet->screen_clock->seconds > 0.2) {
            game->gameplay->tablet->screen_clock->seconds -= 0.2;
            game->gameplay->tablet->background[2]->rect.left += 951;
        }
    } else {
        game->gameplay->tablet->background[1]->pos = set_pos(game,
        (sfVector2f) {129, 99});
        choose_tablet_screen(game);
        display_bg(game->gameplay->tablet->background[1],
        game->game_info->window);
        display_button_tablet(game);
    }
}

void display_tablet(game_t *game)
{
    if (game->gameplay->tablet->display == false &&
    game->gameplay->tablet->background[0]->pos.y < 1080)
        game->gameplay->tablet->background[0]->pos.y +=
        (game->gameplay->tablet->tablet_clock->time.microseconds
        / 1000000.0f) * 1500;
    if (game->gameplay->tablet->background[0]->pos.y > 400 &&
    game->gameplay->tablet->display == true)
        game->gameplay->tablet->background[0]->pos.y -=
        (game->gameplay->tablet->tablet_clock->time.microseconds /
        1000000.0f) * 1500;
    display_bg(game->gameplay->tablet->background[0], game->game_info->window);
    if (game->gameplay->tablet->background[0]->pos.y <= 400 &&
    game->gameplay->tablet->display == true) {
        start_tablet(game);
    }
}
