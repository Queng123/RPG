/*
** EPITECH PROJECT, 2022
** my_arraylen.c
** File description:
** function that calculate the size of array
*/

#include <stdlib.h>

int my_arraylen(char **array)
{
    int a = 0;

    for (; array[a] != NULL; a++);
    return (a);
}
