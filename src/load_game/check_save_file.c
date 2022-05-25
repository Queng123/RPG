/*
** EPITECH PROJECT, 2022
** check_save_file.c
** File description:
** function that check the save if good or no
*/

#include "rpg.h"

int create_informations_save(game_t *game, int i, char **array)
{
    int pos_x = 460;

    if (i == 1)
        pos_x = 860;
    if (i == 2)
        pos_x = 1240;
    create_save_charact(game, i, array[38], pos_x);
    create_name_charact(game, i, pos_x, my_getnbr(array[39]));
    create_date_survivor(game, i, pos_x, array[41]);
    return (0);
}

int check_save_file(game_t *game)
{
    char *filepath[] = {"data/save_1.txt", "data/save_2.txt",
    "data/save_3.txt"};
    char **array = NULL;
    char *str = NULL;

    for (int i = 0; i < 3; i++) {
        str = read_file(filepath[i]);
        if (str == NULL) {
            continue;
        }
        array = my_str_to_word_array(str);
        if (my_arraylen(array) == 43) {
            game->load_game->save[i] = true;
            create_informations_save(game, i, array);
        } else {
            game->load_game->nb_save = i;
            delete_data_file(game);
        }
    }
    return (0);
}
