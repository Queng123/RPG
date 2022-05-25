/*
** EPITECH PROJECT, 2022
** create_date_survivor.c
** File description:
** function that create date survivor for save
*/

#include "rpg.h"

void create_font_position_text(game_t *game, int i, int pos_x)
{
    game->load_game->day[i] = build_text("assets/font/verdana.ttf");
    game->load_game->time[i] = build_text("assets/font/verdana.ttf");
    game->load_game->day[i]->pos = (sfVector2f){pos_x, 730};
    game->load_game->time[i]->pos = (sfVector2f){pos_x, 780};
}

void create_date_survivor(game_t *game, int i, int pos_x, char *time)
{
    int minutes = my_getnbr(time);
    int day = minutes / 1440;
    int heure = 0;
    char *date = NULL;

    minutes = minutes - (1440 * day);
    heure = minutes / 60;
    minutes = minutes - (60 * heure);
    if (minutes < 10)
        date = my_strcat(int_to_char(heure), " : 0");
    else
        date = my_strcat(int_to_char(heure), " : ");
    create_font_position_text(game, i, pos_x);
    sfText_setPosition(game->load_game->day[i]->text,
    game->load_game->day[i]->pos);
    sfText_setPosition(game->load_game->time[i]->text,
    game->load_game->time[i]->pos);
    sfText_setString(game->load_game->day[i]->text,
    my_strcat("DAY: ", int_to_char(day)));
    sfText_setString(game->load_game->time[i]->text,
    my_strcat(date, int_to_char(minutes)));
}
