/*
** EPITECH PROJECT, 2022
** save_data_in_file.c
** File description:
** function that write in file for create save
*/

#include "rpg.h"
#include <fcntl.h>
#include <sys/stat.h>

char *save_data_in_file(char *filepath, game_t *game)
{
    int fd = open(filepath, O_WRONLY);

    if (fd == -1)
        return (NULL);
    write_data_player(fd, game);
    write_data_gameplay(fd, game);
    close(fd);
    return (NULL);
}
