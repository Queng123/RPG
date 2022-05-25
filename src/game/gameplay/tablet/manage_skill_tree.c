/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** manage_skill_tree
*/

#include "rpg.h"

void manage_skill_tree_buttons(game_t *game, sfVector2f click_pos)
{
    for (int i = 4; i != 10; i++)
        if (button_is_clicked(game->gameplay->tablet->button[i], click_pos)
        == 1 && i % 2 == 0 && game->player->point_competences >= 1) {
            game->gameplay->tablet->button[i]->sprite->rect.left = (196 * 2);
            game->gameplay->tablet->button[i]->status = 1;
            game->player->point_competences -= 1;
        } else if (button_is_clicked(game->gameplay->tablet->button[i],
        click_pos)
        == 1 && game->gameplay->tablet->button[i - 1]->status == 1 &&
        game->player->point_competences >= 2) {
            game->gameplay->tablet->button[i]->sprite->rect.left = (196 * 2);
            game->gameplay->tablet->button[i]->status = 1;
            game->player->point_competences -= 2;
        }
}

void set_prize(game_t *game, int i)
{
    if (i % 2 == 0) {
        game->gameplay->tablet->text[0]->str = "1";
    } else {
        game->gameplay->tablet->text[0]->str = "2";
    }
}

void manage_handle_skill_tree(sfMouseMoveEvent event, game_t *game)
{
    sfVector2f click_pos = (sfVector2f) {event.x, event.y};

    if (game->gameplay->tablet->display != true &&
    game->game_info->scene->tablet_scene != SKILL_TREE)
        return;
    for (int i = 4; i != 10; i++) {
        if (button_is_clicked(game->gameplay->tablet->button[i], click_pos)
        == 1 && game->gameplay->tablet->button[i]->status == 0) {
            set_prize(game, i);
            game->gameplay->tablet->button[i]->sprite->rect.left = 196;
            return;
        } else if (game->gameplay->tablet->button[i]->status == 0) {
            game->gameplay->tablet->button[i]->sprite->rect.left = 0;
        }
        game->gameplay->tablet->text[0]->str = " ";
    }
}

void display_cost_and_points(game_t *game)
{
    game->gameplay->tablet->text[0]->pos = set_pos(game,
    (sfVector2f) {210, 635});
    sfText_setPosition(game->gameplay->tablet->text[0]->text,
    game->gameplay->tablet->text[0]->pos);
    sfText_setScale(game->gameplay->tablet->text[0]->text,
    game->gameplay->tablet->text[0]->scale);
    sfText_setString(game->gameplay->tablet->text[0]->text,
    game->gameplay->tablet->text[0]->str);
    sfRenderWindow_drawText(game->game_info->window,
    game->gameplay->tablet->text[0]->text, NULL);
    game->gameplay->tablet->text[1]->pos = set_pos(game,
    (sfVector2f) {975, 635});
    sfText_setPosition(game->gameplay->tablet->text[1]->text,
    game->gameplay->tablet->text[1]->pos);
    sfText_setScale(game->gameplay->tablet->text[1]->text,
    game->gameplay->tablet->text[1]->scale);
    sfText_setString(game->gameplay->tablet->text[1]->text,
    int_to_char(game->player->point_competences));
    sfRenderWindow_drawText(game->game_info->window,
    game->gameplay->tablet->text[1]->text, NULL);
}

void set_pos_skill_tree(game_t *game)
{
    game->gameplay->tablet->button[4]->sprite->pos = set_pos(game,
    (sfVector2f) {210, 307});
    game->gameplay->tablet->button[5]->sprite->pos = set_pos(game,
    (sfVector2f) {210, 145});
    game->gameplay->tablet->button[6]->sprite->pos = set_pos(game,
    (sfVector2f) {510, 307});
    game->gameplay->tablet->button[7]->sprite->pos = set_pos(game,
    (sfVector2f) {510, 145});
    game->gameplay->tablet->button[8]->sprite->pos = set_pos(game,
    (sfVector2f) {810, 307});
    game->gameplay->tablet->button[9]->sprite->pos = set_pos(game,
    (sfVector2f) {810, 145});
    game->gameplay->tablet->background[7]->pos = set_pos(game,
    (sfVector2f) {129, 99});
}
