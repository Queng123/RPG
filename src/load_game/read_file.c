/*
** EPITECH PROJECT, 2022
** read_file.c
** File description:
** function that read a file and storage in buffer
*/

#include "rpg.h"
#include <sys/stat.h>
#include <fcntl.h>

char *read_file(char const *filepath)
{
    char *buffer = NULL;
    int fd = open(filepath, O_RDONLY);
    struct stat size;

    stat(filepath, &size);
    if (fd == -1 || size.st_size == -1)
        return (NULL);
    buffer = malloc(sizeof(char) * (size.st_size + 1));
    if (buffer == NULL)
        return (NULL);
    buffer[size.st_size] = '\0';
    read(fd, buffer, size.st_size);
    if (fd == -1)
        return (NULL);
    close(fd);
    if (buffer[0] == '\0' || fd == -1)
        return (NULL);
    return (buffer);
}
