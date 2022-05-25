/*
** EPITECH PROJECT, 2022
** write_data.c
** File description:
** file with function that write data (player, gameplay)
*/

#include "rpg.h"

int write_data_player(int fd, game_t *game)
{
    for (int i = 0; i < 12; i++)
        write_int_save(fd, game->player->inventory->items[i]->enum_item_e);
    for (int i = 0; i < 12; i++)
        write_int_save(fd, game->player->inventory->items[i]->nb_item);
    write_int_save(fd, game->player->item_hand->enum_item_e);
    write_int_save(fd, game->player->item_hand->nb_item);
    write_int_save(fd, game->player->stat->intellect);
    write_int_save(fd, game->player->stat->shoot);
    write_int_save(fd, game->player->stat->speed);
    write_int_save(fd, game->player->stat->stamina);
    write_int_save(fd, game->player->stat->strength);
    write_int_save(fd, game->player->obj->hp);
    return (0);
}

int write_data_gameplay(int fd, game_t *game)
{
    write_int_save(fd, game->quest->item_collected);
    write_int_save(fd, game->quest->current_level_quest);
    write_int_save(fd, game->map->max_x);
    write_int_save(fd, game->map->max_y);
    write_int_save(fd, game->map->x_player);
    write_int_save(fd, game->map->y_player);
    write_str_save(fd, game->player->filepath_character);
    write_int_save(fd, game->new_game->class);
    write_int_save(fd, game->new_game->color);
    write_int_save(fd, game->gameplay->time);
    write_int_save(fd, game->player->level);
    return (0);
}
