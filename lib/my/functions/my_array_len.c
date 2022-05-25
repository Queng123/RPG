/*
** EPITECH PROJECT, 2022
** B-PSU-101-NAN-1-1-minishell1-quentin.brejoin
** File description:
** my_array_len
*/

#include <unistd.h>

int my_array_len(char **array)
{
    int i = 0;

    for (; array[i] != NULL; i++);
    return (i);
}
