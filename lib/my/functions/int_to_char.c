/*
** EPITECH PROJECT, 2022
** B-MUL-200-NAN-2-1-mydefender-quentin.brejoin
** File description:
** int_to_char
*/

#include "../include/my.h"
#include <stdlib.h>

char *int_to_char(int nb)
{
    char *res = malloc(sizeof(*res) + 2);

    if (res == NULL)
        return (NULL);
    if (nb == 0)
        return ("0");
    for (int i = 0; nb != 0; i++) {
        res[i] = nb % 10 + 48;
        nb = nb / 10;
        res[i + 1] = 0;
    }
    return (my_revstr(res));
}
