/*
** EPITECH PROJECT, 2022
** write_str_and_int.c
** File description:
** file with function that write int or str in file descriptor
*/

#include "rpg.h"

int write_int_save(int fd, int nb)
{
    if (nb < 0) {
        nb = abs(nb);
        if (write(fd, "-", 1) == -1)
            return (84);
    }
    if (write(fd, int_to_char(nb), my_strlen(int_to_char(nb))) == -1)
        return (84);
    if (write(fd, " ", 1) == -1)
        return (84);
    return (0);
}

int write_str_save(int fd, char *str)
{
    if (write(fd, str, my_strlen(str)) == -1)
        return (84);
    if (write(fd, " ", 1) == -1)
        return (84);
    return (0);
}
