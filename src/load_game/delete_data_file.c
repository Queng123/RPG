/*
** EPITECH PROJECT, 2022
** delete_data_file.c
** File description:
** function that delete data in file
*/

#include "rpg.h"
#include <fcntl.h>
#include <unistd.h>

int write_file(char const *filepath, char *buffer)
{
    int fd = open(filepath, O_WRONLY);

    if (fd == -1)
        return (84);
    write(fd, buffer, my_strlen(buffer));
    close(fd);
    return (0);
}

int delete_data_file(game_t *game)
{
    char *filepath[] = {"data/save_1.txt", "data/save_2.txt",
    "data/save_3.txt"};
    char *buffer = NULL;

    buffer = read_file(filepath[game->load_game->nb_save]);
    for (int i = 0; buffer[i] != '\0'; i++)
        buffer[i] = ' ';
    write_file(filepath[game->load_game->nb_save], buffer);
    return (0);
}
