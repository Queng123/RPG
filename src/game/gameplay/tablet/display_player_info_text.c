/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-myrpg-lylian.hay
** File description:
** display_player_info_text
*/

#include "rpg.h"

void display_text_info(text_t *text, sfRenderWindow *window)
{
    sfText_setPosition(text->text, text->pos);
    sfText_setScale(text->text, text->scale);
    sfRenderWindow_drawText(window, text->text, NULL);
}

void display_health_quit(game_t *game)
{
    char *str = NULL;
    sfRenderWindow *win = game->game_info->window;

    str = int_to_char(game->player->stamina_max);
    if (str != NULL) {
        sfText_setString(game->gameplay->tablet->text[4]->text, str);
        display_text_info(game->gameplay->tablet->text[4], win);
    }
    if (my_strcmp("0", str) != 0)
        free(str);
    str = int_to_char(game->player->exp);
    if (str != NULL) {
        sfText_setString(game->gameplay->tablet->text[5]->text, str);
        display_text_info(game->gameplay->tablet->text[5], win);
    }
    if (my_strcmp("0", str) != 0)
        free(str);
}

void display_level_tablet(game_t *game)
{
    char *str = NULL;

    str = int_to_char(game->player->stat->strength);
    if (str != NULL) {
        sfText_setString(game->gameplay->tablet->text[9]->text, str);
        display_text_info(game->gameplay->tablet->text[9],
        game->game_info->window);
    }
    if (my_strcmp("0", str) != 0)
        free(str);
    game->gameplay->tablet->text[11]->pos = set_pos(game,
    (sfVector2f) {273, 525});
    str = int_to_char(game->player->level);
    if (str == NULL)
        return;
    sfText_setString(game->gameplay->tablet->text[11]->text, str);
    display_text_info(game->gameplay->tablet->text[11],
    game->game_info->window);
    if (my_strcmp("0", str) != 0)
        free(str);
}

void display_stat_tablet(game_t *game)
{
    char *str = NULL;
    sfRenderWindow *win = game->game_info->window;

    str = int_to_char(game->player->stat->shoot);
    if (str != NULL) {
        sfText_setString(game->gameplay->tablet->text[7]->text, str);
        display_text_info(game->gameplay->tablet->text[7], win);
    }
    if (my_strcmp("0", str) != 0)
        free(str);
    str = int_to_char(game->player->stat->speed);
    if (str != NULL) {
        sfText_setString(game->gameplay->tablet->text[8]->text, str);
        display_text_info(game->gameplay->tablet->text[8], win);
    }
    if (my_strcmp("0", str) != 0)
        free(str);
    display_level_tablet(game);
    display_player_intellect(game);
}

void display_player_info_text(game_t *game)
{
    char *str = NULL;

    game->gameplay->tablet->text[2]->pos = set_pos(game,
    (sfVector2f) {173, 150});
    sfText_setString(game->gameplay->tablet->text[2]->text,
    game->new_game->name[game->new_game->class]);
    display_text_info(game->gameplay->tablet->text[2], game->game_info->window);
    for (int i = 3; i != 11; i++)
        game->gameplay->tablet->text[i]->pos = set_pos(game,
        (sfVector2f) {940, 25 + i * 55});
    str = int_to_char(game->player->health->current_score);
    if (str != NULL) {
        sfText_setString(game->gameplay->tablet->text[3]->text, str);
        display_text_info(game->gameplay->tablet->text[3],
        game->game_info->window);
    }
    if (my_strcmp("0", str) != 0)
        free(str);
    display_health_quit(game);
    display_stat_tablet(game);
}
