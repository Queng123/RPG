/*
** EPITECH PROJECT, 2022
** launch_save.c
** File description:
** function that launch save choose and start game
*/

#include "rpg.h"
#include "build.h"

void init_save_value(game_t *game, char **array)
{
    for (int i = 0; i < 12; i++)
        game->player->inventory->items[i]->enum_item_e = my_getnbr(array[i]);
    for (int i = 12; i < 24; i++)
        game->player->inventory->items[i - 12]->nb_item = my_getnbr(array[i]);
    game->player->item_hand->enum_item_e = my_getnbr(array[24]);
    game->player->item_hand->nb_item = my_getnbr(array[25]);
    game->player->stat->intellect = my_getnbr(array[26]);
    game->player->stat->shoot = my_getnbr(array[27]);
    game->player->stat->speed = my_getnbr(array[28]);
    game->player->stat->stamina = my_getnbr(array[29]);
    game->player->stat->strength = my_getnbr(array[30]);
    game->player->obj->hp = my_getnbr(array[31]);
    game->quest->item_collected = my_getnbr(array[32]);
    game->quest->current_level_quest = my_getnbr(array[33]);
    game->player->filepath_character = array[38];
    game->new_game->class = my_getnbr(array[39]);
    game->new_game->color = my_getnbr(array[40]);
    game->gameplay->time = my_getnbr(array[41]);
}

int launch_save(game_t *game)
{
    char *filepath[] = {"data/save_1.txt", "data/save_2.txt",
    "data/save_3.txt"};
    char *buffer = NULL;
    char **array = NULL;

    buffer = read_file(filepath[game->load_game->nb_save]);
    array = my_str_to_word_array(buffer);
    game->player = build_player(array[38]);
    game->player->stat = malloc(sizeof(stat_t));
    init_save_value(game, array);
    game->player->level = my_getnbr(array[42]);
    game->player->point_competences = my_getnbr(array[42]) - 1;
    game->chests = build_tab_chest("assets/game/chest.png",
    game->player->inventory->items[0]->sprite_s);
    set_map(game->map, game->chests->chest);
    set_npc_map(game->map, game->quest);
    game->load_game->load_save = game->load_game->nb_save;
    game->game_info->scene->actual_scene = GAME;
    return (0);
}
