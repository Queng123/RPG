/*
** EPITECH PROJECT, 2021
** kjebfz
** File description:
** zmkhreozer
*/

#include <stdlib.h>

int my_strlen(char *);

char *my_strcat(char *str, char *rts)
{
    int len = my_strlen(str) + my_strlen(rts) + 1;
    char *buffer = NULL;
    int i = 0;

    buffer = malloc(sizeof(char) * len + 1);
    for (; i < my_strlen(str); i++)
        buffer[i] = str[i];
    for (int a = 0; i < len; i++, a++)
        buffer[i] = rts[a];
    buffer[len] = '\0';
    return (buffer);
}
