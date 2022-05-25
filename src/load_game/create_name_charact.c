/*
** EPITECH PROJECT, 2022
** create_name_charact.c
** File description:
** function that create name charact of the save
*/

#include "rpg.h"

int create_name_charact(game_t *game, int i, int pos_x, int class)
{
    char *name[] = {"Quentin Brejoin", "Lylian Hay", "Timothee Lesellier",
    "Matthias Gaste"};
    game->load_game->save_charact[i].name =
    build_text("assets/font/verdana.ttf");
    game->load_game->save_charact[i].name->pos = (sfVector2f){pos_x - 60, 360};
    sfText_setPosition(game->load_game->save_charact[i].name->text,
    game->load_game->save_charact[i].name->pos);
    sfText_setString(game->load_game->save_charact[i].name->text, name[class]);
    return (0);
}
